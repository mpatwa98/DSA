// https://leetcode.com/problems/subsets-ii/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& subsets) {
    subsets.push_back(current);

    for (int i = index; i < nums.size(); i++) {
      if (i == index || nums[i] != nums[i - 1]) {
        current.push_back(nums[i]);
        generateSubsets(nums, i + 1, current, subsets);
        current.pop_back();
      }
    }
  }

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> subsets;
    vector<int> current;
    sort(nums.begin(), nums.end());
    generateSubsets(nums, 0, current, subsets);
    return subsets;
  }
};


int main()
{
  Solution obj;

  return 0;
}