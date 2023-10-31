#include <bits/stdc++.h>
using namespace std;

// Approach 1
class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int n = nums.size();
    int index = 1;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
      if (nums[i] == nums[i - 1])
      {
        cnt++;
      }
      else
      {
        cnt = 1;
      }
      nums[index] = nums[i];
      if (cnt <= 2)
      {
        index++;
      }
    }
    return index;
  }
};

// Approach 2
class Solution
{
public:
  int removeDuplicates(vector<int> &nums)
  {
    int i = 0;
    for (auto &e : nums)
    {
      if (i == 0 || i == 1 || nums[i - 2] != e)
      {
        nums[i] = e;
        i++;
      }
    }
    return i;
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