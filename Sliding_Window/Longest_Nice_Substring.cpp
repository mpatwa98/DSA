#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  string longestNiceSubstring(string str)
  {
    // Divide and Conquer
    if (str.length() <= 1)
      return "";

    unordered_set<char> st;
    st.insert(str.begin(), str.end());

    for (int i = 0; i < str.length(); i++)
    {
      char ch = str[i];

      char temp1 = toupper(ch);
      char temp2 = tolower(ch);

      if (st.find(temp1) == st.end() or st.find(temp2) == st.end())
      {
        string left = longestNiceSubstring(str.substr(0, i));
        string right = longestNiceSubstring(str.substr(i + 1, str.length()));

        if (left.length() >= right.length())
        {
          return left;
        }
        else
        {
          return right;
        }
      }
    }
    return str;
  }
};

int main()
{
  Solution obj;

  return 0;
}