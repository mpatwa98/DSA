//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  void solve(int i, string cur, string &s, vector<string> &res)
  {
    if (i == 0)
    {
      solve(i + 1, cur + s[i], s, res);
      return;
    }
    else if (i == s.size())
    {
      res.push_back(cur);
      return;
    }
    if (cur.back() != ' ')
    {
      solve(i, cur + " ", s, res);
    }
    solve(i + 1, cur + s[i], s, res);
  }
  vector<string> permutation(string s)
  {
    string cur = "";
    vector<string> res;
    solve(0, cur, s, res);
    return res;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string S;
    cin >> S;
    vector<string> ans;
    Solution obj;
    ans = obj.permutation(S);
    for (int i = 0; i < ans.size(); i++)
    {
      cout << "(" << ans[i] << ")";
    }
    cout << endl;
  }
}

// } Driver Code Ends