#include <bits/stdc++.h>
using namespace std;

/*
You are given an array of integers nums (0-indexed) and an integer k.
The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.
Return the maximum possible score of a good subarray.
https://leetcode.com/problems/maximum-score-of-a-good-subarray/
*/

class Solution
{
public:
  int maximumScore(vector<int> &nums, int k)
  {
    int mini = nums[k];
    int ans = mini;

    int i = k;
    int j = k;

    while (i > 0 || j < nums.size() - 1)
    {
      if (i == 0 || (j + 1 < nums.size() && nums[i - 1] <= nums[j + 1]))
      {
        j++;
        mini = min(mini, nums[j]);
        ans = max(ans, mini * (j - i + 1));
      }
      else
      {
        i--;
        mini = min(mini, nums[i]);
        ans = max(ans, mini * (j - i + 1));
      }
    }

    return ans;
  }
};

int main()
{
  Solution obj;

  return 0;
}