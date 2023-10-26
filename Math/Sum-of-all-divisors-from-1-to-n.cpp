//{ Driver Code Starts
// Given a positive integer N., The task is to find the value of Σi from 1 to N F(i) where function F(i) for the number i is defined as the sum of all divisors of i.
// https://practice.geeksforgeeks.org/problems/sum-of-all-divisors-from-1-to-n4738/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
  long long sumOfDivisors(int n)
  {
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
      ans += (n / i) * i;
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
    int N;
    cin >> N;
    Solution ob;
    long long ans = ob.sumOfDivisors(N);
    cout << ans << endl;
  }
  return 0;
}
// } Driver Code Ends