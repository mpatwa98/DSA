//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\'' << x << '\'';}
void __print(const string &x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*
Given an array of N elements and L and R, 
print the number of sub-arrays such that 
the value of the maximum array element in that subarray is
 at least L and at most R.
*/

// } Driver Code Ends

class Solution
{
public:
  long countSubarrays(int a[], int n, int L, int R)
  {
    long long ans = 0;
    long long small = 0;
    long long valid = 0;

    for (int i = 0; i < n; i++)
    {
      if (a[i] > R)
      {
        ans += (valid * (valid + 1)) / 2;
        ans -= (small * (small + 1)) / 2;

        valid = small = 0;
      }
      else if (a[i] < L)
      {
        ++valid;
        ++small;
      }
      else
      {
        ans -= (small * (small + 1)) / 2;
        small = 0;
        ++valid;
      }
    }

    ans += (valid * (valid + 1)) / 2;
    ans -= (small * (small + 1)) / 2;

    return ans;
  }
};

//{ Driver Code Starts.
// driver program
int main()
{
  int t;
  cin >> t;
  while (t--)
  {

    int n, l, r;
    cin >> n >> l >> r;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.countSubarrays(a, n, l, r) << endl;
  }
  return 0;
}

// } Driver Code Ends