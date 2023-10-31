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

int minDepth(TreeNode *root)
{
  // Corner case. Should never be hit unless the code is called on root = NULL
  if (root == NULL)
    return 0;
  // Base case : Leaf node. This accounts for height = 1.
  if (root->left == NULL && root->right == NULL)
    return 1;

  if (!root->left)
    return minDepth(root->right) + 1;
  if (!root->right)
    return minDepth(root->left) + 1;

  return min(minDepth(root->left), minDepth(root->right)) + 1;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Solution obj;

  return 0;
}