#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> pivotArray(vector<int> &n, int p)
  {
    const int sizeN = n.size();

    for (int d = 2; d < 2 * sizeN; d <<= 1)
    {
      auto b = begin(n);
      auto m = b;
      auto e = b;

      while (b < end(n))
      {
        m = std::min(b + d / 2, end(n));
        e = std::min(b + d, end(n));

        auto l = std::lower_bound(b, m, p);
        auto h = std::upper_bound(m, e, p);

        std::rotate(l, m, h);
        b = e;
      }
    }
    return n;
  }
};
int main()
{
  Solution obj;

  return 0;
}