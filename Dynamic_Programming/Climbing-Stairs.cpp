#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  // Bottom Up
  int climbStairsUtil(int i, vector<int> &dp)
  {
    if (i == 1 || i == 2)
      return i;
    if (dp[i] != -1)
    {
      return dp[i];
    }
    int one = climbStairsUtil(i - 1, dp);
    int two = climbStairsUtil(i - 2, dp);
    return dp[i] = one + two;
  }
  int climbStairs(int n)
  {
    vector<int> dp(n + 1, -1);
    return climbStairsUtil(n, dp);
  }

  // Top Down
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++)
    {
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
  }
  
  // Space Optimized
  int climbStairs(int n)
  {
    if (n <= 2)
      return n;
    int first = 1;
    int second = 2;
    int res = 0;
    for (int i = 3; i <= n; i++)
    {
      res = first + second;
      first = second;
      second = res;
    }

    return res;
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