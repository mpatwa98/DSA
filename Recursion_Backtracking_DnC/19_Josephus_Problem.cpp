//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// https://practice.geeksforgeeks.org/problems/josephus-problem/1
/*You are required to complete this method */

class Solution
{
public:
  // TC: O(N)
  // SC: O(N)
  // Array Approach
  int Josh(vector<int> &person, int k, int index)
  {
    if (person.size() == 1)
    {
      return person[0];
    }
    index = ((index + k) % person.size());
    person.erase(person.begin() + index);
    return Josh(person, k, index);
  }
  int josephus(int n, int k)
  {
    k--;
    int index = 0;

    vector<int> person;
    for (int i = 1; i <= n; i++)
    {
      person.push_back(i);
    }

    return Josh(person, k, index);
  }
};

class Solution
{
public:
  // TC: O(N)
  // SC: O(N) Depth of recursion tree
  // Math Approach
  int josephus(int n, int k)
  {
    if (n == 1)
    {
      return 1;
    }
    else
    {
      return (josephus(n - 1, k) + k - 1) % n + 1;
    }
  }
};

//{ Driver Code Starts.

int main()
{

  int t;
  cin >> t; // testcases
  while (t--)
  {
    int n, k;
    cin >> n >> k; // taking input n and k

    // calling josephus() function
    Solution ob;
    cout << ob.josephus(n, k) << endl;
  }
  return 0;
}
// } Driver Code Ends