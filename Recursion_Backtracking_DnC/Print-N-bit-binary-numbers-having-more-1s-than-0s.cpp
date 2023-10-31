//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
  vector<string> res;
  void solve(int i, string &cur, int n, int one, int zero)
  {
    if (i == n)
    {
      res.push_back(cur);
      return;
    }
    cur.push_back('1');
    solve(i + 1, cur, n, one + 1, zero);
    cur.pop_back();
    if (one > zero)
    {
      cur.push_back('0');
      solve(i + 1, cur, n, one, zero + 1);
      cur.pop_back();
    }
  }
  vector<string> NBitBinary(int N)
  {
    string cur = "";
    solve(0, cur, N, 0, 0);
    return res;
  }
};

//{ Driver Code Starts.

int main()
{

  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    Solution ob;
    vector<string> ans = ob.NBitBinary(n);

    for (auto i : ans)
      cout << i << " ";

    cout << "\n";
  }

  return 0;
}
// } Driver Code Ends