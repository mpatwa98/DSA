/*
https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
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
  int sum = 0;
  void c(TreeNode *root)
  {
    if (root == NULL)
      return;
    int x = 0;
    if (root->left)
      x += root->left->val;
    if (root->right)
      x += root->right->val;
    sum += x;
  }
  int sumEvenGrandparent(TreeNode *root)
  {
    if (root == NULL)
      return 0;
    if (root->val % 2 == 0)
    {
      c(root->left);
      c(root->right);
    }
    sumEvenGrandparent(root->left);
    sumEvenGrandparent(root->right);
    return sum;
  }
};

int main()
{
  Solution obj;

  return 0;
}