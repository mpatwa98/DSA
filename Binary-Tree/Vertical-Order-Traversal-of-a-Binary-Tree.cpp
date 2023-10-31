#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    vector<vector<int>> res;
    if (root == NULL)
    {
      return res;
    }
    queue<pair<TreeNode *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> mp;
    q.push({root, {0, 0}});
    int left = 0, right = 0;
    while (!q.empty())
    {
      auto it = q.front();
      q.pop();
      TreeNode *node = it.first;
      int row = it.second.first;
      int col = it.second.second;
      mp[col][row].insert(node->val);
      if (node->left)
      {
        q.push({node->left, {row + 1, col - 1}});
      }
      if (node->right)
      {
        q.push({node->right, {row + 1, col + 1}});
      }
    }
    for (auto &p : mp)
    {
      vector<int> col;
      for (auto &pp : p.second)
      {
        col.insert(col.end(), pp.second.begin(), pp.second.end());
      }
      res.push_back(col);
    }
    return res;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  Solution obj;

  return 0;
}