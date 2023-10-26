#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
  int data;
  Node *left;
  Node *right;
};

// Recursive function to print all the nodes at distance k in the
// tree (or subtree) rooted with given root. See */
void printKDistanceNodeDown(Node *root, int k)
{
  // Base Case
  if (root == NULL || k < 0)
    return;

  // If we reach a k distant node, print it
  if (k == 0)
  {
    cout << root->data << endl;
    return;
  }

  // Recur for left and right subtrees
  printKDistanceNodeDown(root->left, k - 1);
  printKDistanceNodeDown(root->right, k - 1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward. This function
// Returns distance of root from target node, it returns
// -1 if target node is not present in tree rooted with root.
int printKDistanceNode(Node *root, Node *target, int k)
{
  // Base Case 1: If tree is empty, return -1
  if (root == NULL)
    return -1;

  // If target is same as root. Use the downward function
  // to print all nodes at distance k in subtree rooted with
  // target or root
  if (root == target)
  {
    printKDistanceNodeDown(root, k);
    return 0;
  }

  // Recur for left subtree
  int dl = printKDistanceNode(root->left, target, k);

  // Check if target node was found in left subtree
  if (dl != -1)
  {
    // If root is at distance k from target, print root
    // Note that dl is Distance of root's
    // left child from target
    if (dl + 1 == k)
      cout << root->data << endl;

    // Else go to right subtree and print all k-dl-2
    // distant nodes Note that the right child is 2
    // edges away from left child
    else
      printKDistanceNodeDown(root->right, k - dl - 2);

    // Add 1 to the distance and return value for parent calls
    return 1 + dl;
  }

  // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
  // Note that we reach here only when node was
  // not found in left subtree
  int dr = printKDistanceNode(root->right, target, k);
  if (dr != -1)
  {
    if (dr + 1 == k)
      cout << root->data << endl;
    else
      printKDistanceNodeDown(root->left, k - dr - 2);
    return 1 + dr;
  }

  // If target was neither present in left
  // nor in right subtree
  return -1;
}

// A utility function to create a new binary tree node
Node *newNode(int data)
{
  Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

// Driver program to test above functions
int main()
{
  // Let us construct the tree shown in above diagram
  Node *root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  Node *target = root->left->right;
  printKDistanceNode(root, target, 2);
  return 0;
}
