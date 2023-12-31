//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

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
void __print(const char *x) { cerr << '\'' << x << '\''; }
void __print(const string &x) { cerr << '\'' << x << '\''; }
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

// } Driver Code Ends

class Solution
{
public:
  int buyMaximumProducts(int n, int k, int price[])
  {
    typedef std::pair<int, int> PriceIndexPair;
    std::vector<PriceIndexPair> v;

    for (int i = 0; i < n; ++i)
    {
      v.emplace_back(price[i], i);
    }

    std::sort(v.begin(), v.end());

    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
      int e = k / v[i].first;
      k -= std::min(e, v[i].second + 1) * v[i].first;
      sum += std::min(e, v[i].second + 1);
    }

    return sum;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, k;
    cin >> n >> k;
    int price[n];
    for (int i = 0; i < n; i++)
    {
      cin >> price[i];
    }
    Solution ob;
    int ans = ob.buyMaximumProducts(n, k, price);
    cout << ans << endl;
  }
  return 0;
}

// } Driver Code Ends