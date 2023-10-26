#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  uint32_t reverseBits(uint32_t n, int len = 16)
  {
    if (len == 0)
      return n;
    uint32_t mask = (1 << len) - 1;
    uint32_t l = reverseBits(n >> len, len >> 1);
    uint32_t r = reverseBits(n & mask, len >> 1);
    return (r << len) + l;
  }
};

int main()
{
  Solution obj;

  return 0;
}