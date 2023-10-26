#include <bits/stdc++.h>
using namespace std;

/*
https://leetcode.com/problems/number-of-flowers-in-full-bloom/

alternative to +1 on open and -1 on after close
from this start to that end in range 
*/

class Solution
{
public:
  vector<int> fullBloomFlowers(vector<vector<int>> &flowers, vector<int> &persons)
  {
    vector<int> start, end;
    for (auto &t : flowers)
    {
      start.push_back(t[0]);
      end.push_back(t[1]);
    }
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());
    vector<int> res;
    for (int t : persons)
    {
      int started = upper_bound(start.begin(), start.end(), t) - start.begin();
      int ended = lower_bound(end.begin(), end.end(), t) - end.begin();
      res.push_back(started - ended);
    }
    return res;
  }
};

int main()
{
  Solution obj;

  return 0;
}