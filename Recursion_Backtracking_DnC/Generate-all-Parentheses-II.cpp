#include <bits/stdc++.h>
using namespace std;

void solve(int i, int n, int open, int close, string &cur, vector<string> &res)
{
  if (i >= 2 * n)
  {
    res.push_back(cur);
    return;
  }

  if (open > close && close < n)
  {
    cur.push_back(')');
    solve(i + 1, n, open, close + 1, cur, res);
    cur.pop_back();
  }
  if (open < n)
  {
    cur.push_back('(');
    solve(i + 1, n, open + 1, close, cur, res);
    cur.pop_back();
  }
}

vector<string> generateParenthesis(int A)
{
  vector<string> res;
  string cur = "";
  solve(0, A, 0, 0, cur, res);
  sort(res.begin(), res.end());
  return res;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;
  auto ans = generateParenthesis(n);
  for (auto &it : ans)
  {
    cout << it << "\n";
  }

  return 0;
}