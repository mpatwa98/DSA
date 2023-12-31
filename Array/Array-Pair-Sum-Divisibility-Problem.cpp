//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  bool canPair(vector<int> nums, int k)
  {
    int n = nums.size();
    if (n & 1)
    {
      return false;
    }
    unordered_map<int, int> mp;
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      mp[nums[i] % k]++;
      sum += nums[i];
    }
    if (sum % k != 0 && sum >= (n / 2) * k)
    {
      return false;
    }
    for (auto &it : mp)
    {
      if (it.first == 0 || (!(k & 1) && it.first == k / 2))
      {
        if (it.second & 1)
        {
          return false;
        }
      }
      else
      {
        auto index = mp.find(k - it.first);
        if (index != mp.end() && it.second == index->second)
        {
          mp.erase(index);
        }
        else
        {
          return false;
        }
      }
    }
    return true;
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
      cin >> nums[i];
    Solution ob;
    bool ans = ob.canPair(nums, k);
    if (ans)
      cout << "True\n";
    else
      cout << "False\n";
  }
  return 0;
}
// } Driver Code Ends