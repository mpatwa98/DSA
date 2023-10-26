#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//   // TC: O(log4(N))
//   bool isPowerOfFour(int n)
//   {
//     if (n <= 0)
//     {
//       return false;
//     }
//     while (n % 4 == 0)
//     {
//       n /= 4;
//     }
//     if (n == 1)
//     {
//       return true;
//     }
//     return false;
//   }
// };

// class Solution
// {
// public:
//   // TC: O(log(N)+log(x))
//   bool isPowerOfFour(int n)
//   {
//     if (n <= 0)
//     {
//       return false;
//     }
//     int x = log(n) / log(4);
//     if (pow(4, x) == n)
//     {
//       return true;
//     }
//     return false;
//   }
// };

class Solution
{
public:
  // TC: O(1)
  bool isPowerOfFour(int n)
  {
    if (n <= 0)
    {
      return false;
    }
    if ((n & (n - 1)) == 0 && (n - 1) % 3 == 0)
    {
      return true;
    }
    return false;
  }
};

int main()
{
  Solution obj;

  return 0;
}