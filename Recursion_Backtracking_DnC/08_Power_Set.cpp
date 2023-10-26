//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  vector<string> ans;
  void solve(int i, string &cur, int n, string &s)
  {
    if (i == n)
    {
      if (!cur.empty())
        ans.push_back(cur);
      return;
    }
    cur.push_back(s[i]);
    solve(i + 1, cur, n, s);
    cur.pop_back();
    solve(i + 1, cur, n, s);
  }
  vector<string> AllPossibleStrings(string s)
  {
    string cur = "";
    int n = s.size();
    solve(0, cur, n, s);
    sort(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    string s;
    cin >> s;
    Solution ob;
    vector<string> res = ob.AllPossibleStrings(s);
    for (auto i : res)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends