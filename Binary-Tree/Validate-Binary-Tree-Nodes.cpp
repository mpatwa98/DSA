/*
A binary tree is valid if it satisfies the following conditions:
1. It has a single root node.
2. Each non-root node has exactly one parent node.
3. The tree is connected, meaning all nodes are reachable from the root.
4. There are no cycles in the tree.
https://leetcode.com/problems/validate-binary-tree-nodes/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
  {
    vector<int> inDegree(n);
    for (int node = 0; node < n; node++)
    {
      int left = leftChild[node];
      int right = rightChild[node];
      if (left != -1)
      {
        inDegree[left]++;
      }
      if (right != -1)
      {
        inDegree[right]++;
      }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
      if (inDegree[i] == 0)
      {
        q.push(i);
      }
      if (inDegree[i] > 1)
      {
        return false;
      }
    }
    if (q.size() > 1)
    {
      return false;
    }
    vector<int> vis(n);
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      if (it == -1)
      {
        continue;
      }
      if (vis[it] == 1)
      {
        return false;
      }
      vis[it] = 1;
      q.push(leftChild[it]);
      q.push(rightChild[it]);
    }
    return count(vis.begin(), vis.end(), 0) == 0;
  }
};

int main()
{
  Solution obj;

  return 0;
}