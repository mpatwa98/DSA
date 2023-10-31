#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  const int mod = 1e9 + 7;

  long long binPow(long long base, long long power)
  {
    long long res = 1;
    base = base % mod;
    while (power > 0)
    {
      if (power & 1)
      {
        res = (res * base) % mod;
      }
      base = (base * base) % mod;
      power >>= 1;
    }
    return res;
  }

  int countGoodNumbers(long long n)
  {
    if (n == 1)
    {
      return 5 % mod;
    }
    long long p = (n + 1) / 2;
    long long res = (binPow(5, p) * binPow(4, n - p)) % mod;
    return res;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Solution obj;
  long long n;
  cin >> n;
  cout << obj.countGoodNumbers(n);

  return 0;
}