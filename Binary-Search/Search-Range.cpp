/*
https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    const int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (l == nums.size() || nums[l] != target)
      return {-1, -1};
    const int r =
        upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {l, r};
  }
};

int main()
{
  Solution obj;

  return 0;
}