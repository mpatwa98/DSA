//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
  int data;
  Node *left;
  Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
  Node *temp = new Node;
  temp->data = val;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
  // Corner Case
  if (str.length() == 0 || str[0] == 'N')
    return NULL;

  // Creating vector of strings from input
  // string after spliting by space
  vector<string> ip;

  istringstream iss(str);
  for (string str; iss >> str;)
    ip.push_back(str);

  // Create the root of the tree
  Node *root = newNode(stoi(ip[0]));

  // Push the root to the queue
  queue<Node *> queue;
  queue.push(root);

  // Starting from the second element
  int i = 1;
  while (!queue.empty() && i < ip.size())
  {

    // Get and remove the front of the queue
    Node *currNode = queue.front();
    queue.pop();

    // Get the current node's value from the string
    string currVal = ip[i];

    // If the left child is not null
    if (currVal != "N")
    {

      // Create the left child for the current node
      currNode->left = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->left);
    }

    // For the right child
    i++;
    if (i >= ip.size())
      break;
    currVal = ip[i];

    // If the right child is not null
    if (currVal != "N")
    {

      // Create the right child for the current node
      currNode->right = newNode(stoi(currVal));

      // Push it to the queue
      queue.push(currNode->right);
    }
    i++;
  }

  return root;
}

// } Driver Code Ends
/* A binary Tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
*/

// Nodes at given distance in binary tree
// BFS
// TC: O(N)
// SC: O(N)
class Solution
{
public:
  void storeParent(Node *root, int target, unordered_map<Node *, Node *> &parent, Node *&temp)
  {
    if (root->data == target && temp == NULL)
      temp = root;
    if (root->left != NULL)
    {
      parent[root->left] = root;
      storeParent(root->left, target, parent, temp);
    }
    if (root->right != NULL)
    {
      parent[root->right] = root;
      storeParent(root->right, target, parent, temp);
    }
  }
  vector<int> KDistanceNodes(Node *root, int target, int k)
  {
    unordered_map<Node *, Node *> parent;
    Node *temp = NULL;
    storeParent(root, target, parent, temp);
    unordered_map<Node *, int> vis;
    vis[temp] = 1;
    vector<int> ans;
    queue<pair<Node *, int>> q;
    q.push({temp, k});
    while (q.size() > 0)
    {
      auto it = q.front();
      q.pop();
      if (it.second == 0)
      {
        ans.push_back(it.first->data);
      }
      Node *r = it.first;
      if (r->left != NULL && vis.find(r->left) == vis.end())
      {
        q.push({r->left, it.second - 1});
        vis[r] = 1;
      }
      if (r->right != NULL && vis.find(r->right) == vis.end())
      {
        q.push({r->right, it.second - 1});
        vis[r] = 1;
      }
      if (parent.find(r) != parent.end() && vis.find(parent[r]) == vis.end())
      {
        q.push({parent[r], it.second - 1});
        vis[parent[r]] = 1;
      }
    }
    sort(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  getchar();

  Solution x = Solution();

  while (t--)
  {
    string s;
    getline(cin, s);
    Node *head = buildTree(s);

    int target, k;
    cin >> target >> k;
    getchar();

    vector<int> res = x.KDistanceNodes(head, target, k);

    for (int i = 0; i < res.size(); i++)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends