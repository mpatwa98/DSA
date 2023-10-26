//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // You need to complete this function

  // avoid space at the starting of the string in "move disk....."
  long long steps = 0;
  long long toh(int N, int from, int to, int aux)
  {
    if (N == 0)
    {
      return steps;
    }
    toh(N - 1, from, aux, to);
    steps++;
    cout << "move disk " << N << " from rod " << from << " to rod " << to << "\n";
    toh(N - 1, aux, to, from);
  }
};

//{ Driver Code Starts.

int main()
{

  int T;
  cin >> T; // testcases
  while (T--)
  {

    int N;
    cin >> N; // taking input N

    // calling toh() function
    Solution ob;

    cout << ob.toh(N, 1, 3, 2) << endl;
  }
  return 0;
}

// } Driver Code Ends