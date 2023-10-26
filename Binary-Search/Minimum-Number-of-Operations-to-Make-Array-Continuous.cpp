#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
/*
You are given an integer array nums. In one operation, you can replace any element in nums with any integer.

nums is considered continuous if both of the following conditions are fulfilled:

    All elements in nums are unique.
    The difference between the maximum element and the minimum element in nums equals nums.length - 1.

For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.

Return the minimum number of operations to make nums continuous.
*/

class Solution
{
public:
  int minOperations(vector<int> &nums)
  {
    int n = nums.size(), mn = INT_MAX;
    set<int> s;
    for (int i = 0; i < n; i++)
    {
      s.insert(nums[i]);
    }
    vector<int> temp(s.begin(), s.end());
    for (int i = 0; i < temp.size(); i++)
    {
      auto it = temp[i];
      int r = it + n - 1;
      int inRange = upper_bound(temp.begin() + i, temp.end(), r) - (temp.begin() + i);
      mn = min(mn, n - inRange);
    }
    return mn;
  }
};

int main()
{
  Solution obj;

  return 0;
}