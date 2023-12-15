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

// Morris traversel
// Benefit - no auxilary stack space for recursion
// T.C : O(n)
// S.C : O(1) - Not including result array
class Solution
{
public:
  vector<int> inorderTraversal(TreeNode *root)
  {
    vector<int> result;
    TreeNode *curr = root;
    TreeNode *pre;

    while (curr != nullptr)
    {
      if (curr->left == nullptr)
      {
        result.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        pre = curr->left;

        while (pre->right != nullptr)
        {
          pre = pre->right;
        }

        pre->right = curr;
        TreeNode *temp = curr;
        curr = curr->left;
        temp->left = nullptr;
      }
    }

    return result;
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