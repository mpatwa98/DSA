#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  typedef pair<int, int> P;
  int constrainedSubsetSum(vector<int> &nums, int k)
  {
    int n = nums.size();

    vector<int> dp(n, 0);
    dp = nums;
    priority_queue<P, vector<P>> pq;
    pq.push({dp[0], 0});

    int maxR = dp[0];

    for (int i = 1; i < n; i++)
    {

      while (!pq.empty() && pq.top().second < i - k)
      {
        pq.pop();
      }

      dp[i] = max(dp[i], nums[i] + pq.top().first);
      pq.push({dp[i], i});

      maxR = max(maxR, dp[i]);
    }

    return maxR;
  }
};

int main()
{
  Solution obj;

  return 0;
}