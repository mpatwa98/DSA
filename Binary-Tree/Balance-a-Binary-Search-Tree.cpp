// https://leetcode.com/problems/balance-a-binary-search-tree/
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
  vector<TreeNode *> sorted;

public:
  void inOrder(TreeNode *root)
  {
    if (root == NULL)
      return;

    inOrder(root->left);
    sorted.push_back(root);
    inOrder(root->right);
  }

  TreeNode *createTree(int start, int end)
  {
    if (start > end)
      return NULL;

    int mid = start + (end - start) / 2;
    TreeNode *root = sorted[mid];
    root->left = createTree(start, mid - 1);
    root->right = createTree(mid + 1, end);
    return root;
  }
  TreeNode *balanceBST(TreeNode *root)
  {
    inOrder(root);
    return createTree(0, sorted.size() - 1);
  }
};

int main()
{
  Solution obj;

  return 0;
}