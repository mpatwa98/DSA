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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution
{
public:
  int curNum = 0;
  int curFreq = 0;
  int maxFreq = 0;
  vector<int> res;
  void inOrder(TreeNode *root)
  {
    if (!root)
      return;

    inOrder(root->left);

    if (root->val == curNum)
    {
      curFreq++;
    }
    else
    {
      curNum = root->val;
      curFreq = 1;
    }

    if (curFreq > maxFreq)
    {
      res = {};
      maxFreq = curFreq;
    }
    if (curFreq == maxFreq)
    {
      res.push_back(root->val);
    }
    inOrder(root->right);
  }
  vector<int> findMode(TreeNode *root)
  {
    inOrder(root);
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