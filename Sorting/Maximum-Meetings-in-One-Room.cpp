//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Meeting
{
public:
  int index;
  int start;
  int finish;

  Meeting(int _start, int _finish, int _index) : start(_start), finish(_finish), index(_index) {}
};

class Solution
{
public:
  vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F)
  {
    vector<Meeting> meetings;
    for (int i = 0; i < N; i++)
    {
      meetings.emplace_back(S[i], F[i], i + 1);
    }

    sort(meetings.begin(), meetings.end(), [](const Meeting &m1, const Meeting &m2)
         { return (m1.finish == m2.finish) ? (m1.start < m2.start) : (m1.finish < m2.finish); });

    vector<int> ans;
    ans.push_back(meetings[0].index);

    int limit = meetings[0].finish;

    for (int i = 1; i < N; i++)
    {
      if (meetings[i].start > limit)
      {
        limit = meetings[i].finish;
        ans.push_back(meetings[i].index);
      }
    }
    sort(ans.begin(), ans.end());

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
    int n;
    cin >> n;
    vector<int> S(n), F(n);
    for (int i = 0; i < n; i++)
    {
      cin >> S[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> F[i];
    }
    Solution ob;
    vector<int> ans = ob.maxMeetings(n, S, F);
    for (int i = 0; i < ans.size(); i++)
    {
      cout << ans[i];
      if (i != ans.size() - 1)
      {
        cout << " ";
      }
    }
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends