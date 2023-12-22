#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *links[26];
  bool flag = false;

  bool containKey(char &ch)
  {
    return (links[ch - 'a'] != NULL);
  }
  void put(char &ch, Node *node)
  {
    links[ch - 'a'] = node;
  }
  Node *get(char &ch)
  {
    return links[ch - 'a'];
  }
  void setEnd()
  {
    flag = true;
  }
  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
private:
  Node *root;

public:
  Trie()
  {
    root = new Node();
  }

  void insert(string &word)
  {
    Node *node = root;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
      if (!(node->containKey(word[i])))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  bool search(string &word)
  {
    Node *node = root;
    int n = word.size();
    for (int i = 0; i < n; i++)
    {
      if (!(node->containKey(word[i])))
      {
        return false;
      }
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  bool startsWith(string &prefix)
  {
    Node *node = root;
    int n = prefix.size();
    for (int i = 0; i < n; i++)
    {
      if (!(node->containKey(prefix[i])))
      {
        return false;
      }
      node = node->get(prefix[i]);
    }
    return true;
  }
};

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // Solution obj;

  return 0;
}