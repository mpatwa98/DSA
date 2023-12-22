#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int posOfRightMostDiffBit(int m, int n)
  {
    // XOR the two numbers to find the differing bits.
    int xorResult = m ^ n;

    // If the numbers are equal, there are no differing bits.
    if (xorResult == 0)
    {
      return -1;
    }

    // Find the position of the rightmost set bit in the XOR result.
    return log2(xorResult & -xorResult) + 1;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Solution obj;

  return 0;
}