#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void merge(int start, int mid, int end, vector<int> &nums)
  {
    int lsz = mid - start + 1, rsz = end - (mid + 1) + 1;
    vector<int> left(lsz + 1), right(rsz + 1);
    int cur = 0;
    for (int i = start; i <= mid; i++)
    {
      left[cur++] = nums[i];
    }
    left[cur] = INT_MAX;
    cur = 0;
    for (int i = mid + 1; i <= end; i++)
    {
      right[cur++] = nums[i];
    }
    right[cur] = INT_MAX;
    cur = start;
    int l = 0, r = 0;
    while (cur <= end)
    {
      if (left[l] <= right[r])
        nums[cur++] = left[l++];
      else
        nums[cur++] = right[r++];
    }
  }
  void mergeSort(int start, int end, vector<int> &nums)
  {
    if (start == end)
      return;
    int mid = start + (end - start) / 2;
    mergeSort(start, mid, nums);
    mergeSort(mid + 1, end, nums);
    merge(start, mid, end, nums);
    return;
  }
  vector<int> sortArray(vector<int> &nums)
  {
    int n = nums.size();
    mergeSort(0, n - 1, nums);
    return nums;
  }
};

int main()
{
  Solution obj;

  return 0;
}