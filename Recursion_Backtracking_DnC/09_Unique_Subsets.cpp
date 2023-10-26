//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to find all possible unique subsets.
  set<vector<int>> s;
  // do not put & before cur 
  // because after sorting different element might be pop out
  void solve(int i, vector<int> cur, int n, vector<int> &arr)
  {
    if (i == n)
    {
      sort(cur.begin(), cur.end());
      s.insert(cur);
      return;
    }
    cur.push_back(arr[i]);
    solve(i + 1, cur, n, arr);
    cur.pop_back();
    solve(i + 1, cur, n, arr);
  }
  vector<vector<int>> AllSubsets(vector<int> arr, int n)
  {
    vector<int> cur;
    solve(0, cur, n, arr);
    vector<vector<int>> ans;
    for (auto &it : s)
    {
      ans.push_back(it);
    }

    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> A;
    int x;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      A.push_back(x);
    }
    Solution obj;
    vector<vector<int>> result = obj.AllSubsets(A, n);
    // printing the output
    for (int i = 0; i < result.size(); i++)
    {
      cout << '(';
      for (int j = 0; j < result[i].size(); j++)
      {
        cout << result[i][j];
        if (j < result[i].size() - 1)
          cout << " ";
      }
      cout << ")";
    }
    cout << "\n";
  }
}

// } Driver Code Ends