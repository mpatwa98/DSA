/*
Height of Tree means max count of nodes from root to leaf
*/

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
  // TC: O(N) N=number of nodes
  // SC: O(1)
  int maxDepth(TreeNode *root)
  {
    if (root == NULL)
      return 0;

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return 1 + max(lh, rh);
  }
};

int main()
{
  Solution obj;
  TreeNode *bt = new TreeNode(7);
  bt->left = new TreeNode(8);
  bt->left->left = new TreeNode(9);
  cout << obj.maxDepth(bt);

  return 0;
}