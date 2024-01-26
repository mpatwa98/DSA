#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
#define fr first
#define sc second
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
  cerr << '{';
  __print(x.first);
  cerr << ',';
  __print(x.second);
  cerr << '}';
}
template <typename T>
void __print(const T &x)
{
  int f = 0;
  cerr << '{';
  for (auto &i : x)
    cerr << (f++ ? "," : ""), __print(i);
  cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)             \
  cerr << "[" << #x << "] = ["; \
  _print(x)
#else
#define debug(x...)
#endif

ll power(ll base, ll p)
{
  ll res = 1;
  base = base % M;
  while (p > 0)
  {
    if (p & 1)
    {
      res = (res * base) % M;
      p--;
    }
    base = (base * base) % M;
    p >>= 1;
  }
  return res;
}
int dp[100001][4];
// int rec(int i, int prev, vector<int> &a, vector<int> &b, vector<int> &c)
// {
//   if (i < 0)
//   {
//     return 0;
//   }
//   if (dp[i][prev] != -1)
//   {
//     return dp[i][prev];
//   }
//   int swim = 0, bugs = 0, hw = 0;
//   if (prev != 1)
//     swim = a[i] + rec(i - 1, 1, a, b, c);
//   if (prev != 2)
//   {
//     bugs = b[i] + rec(i - 1, 2, a, b, c);
//   }
//   if (prev != 3)
//   {
//     hw = c[i] + rec(i - 1, 3, a, b, c);
//   }
//   return dp[i][prev] = max({swim, bugs, hw});
// }

void solve()
{
  int n;
  cin >> n;
  vector<int> a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i] >> b[i] >> c[i];
  }
  memset(dp, -1, sizeof(dp));
  // int ans = rec(n - 1, 0, a, b, c);
  int ans = 0;
  dp[0][1] = a[0];
  dp[0][2] = b[0];
  dp[0][3] = c[0];
  for (int i = 1; i < n; i++)
  {
    dp[i][1] = a[i] + max(dp[i - 1][2], dp[i - 1][3]);
    dp[i][2] = b[i] + max(dp[i - 1][1], dp[i - 1][3]);
    dp[i][3] = c[i] + max(dp[i - 1][1], dp[i - 1][2]);
  }
  ans = max({dp[n - 1][1], dp[n - 1][2], dp[n - 1][3]});
  cout << ans;
}

int32_t main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
  auto start = chrono::high_resolution_clock::now();

  int t = 1;
  // cin>>t;
  for (int tc = 1; tc <= t; ++tc)
  {
    solve();
  }
  auto stop = chrono::high_resolution_clock::now();
  auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
  cerr << duration.count() / 1000.0 << ' ' << 'm' << 's';

  return 0;
}
