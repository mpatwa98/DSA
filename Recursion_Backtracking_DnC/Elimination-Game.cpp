#include <bits/stdc++.h>
using namespace std;

#include <vector>

class Solution
{
public:
  int lastRemaining(int n)
  {
    int head = 1;
    int step = 1;
    bool left = true;
    int remain = n;
    while (remain > 1)
    {
      if (left || remain & 1)
      {
        head += step;
      }
      remain /= 2;
      step *= 2;
      left = !left;
    }
    return head;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Solution obj;
  int n;
  cin >> n;
  cout << obj.lastRemaining(n);

  return 0;
}