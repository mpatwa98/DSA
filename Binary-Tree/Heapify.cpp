#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
  int arr[100];
  int size = 0;

  void insert(int val)
  {
    size = size + 1;
    int index = size;
    arr[index] = val;
    while (index > 1)
    {
      if (arr[index / 2] < arr[index])
      {
        swap(arr[index / 2], arr[index]);
        index = index / 2;
      }
      else
      {
        return;
      }
    }
  }

  void print()
  {
    for (int i = 1; i < size; i++)
    {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }

  void deleteFromHeap(){
    arr[1]=arr[size];
    size--;
    while(index)
  }
};

int main()
{
  heap h;
  h.insert(1);
  h.insert(2);
  h.insert(3);
  h.insert(4);
  h.insert(5);
  h.insert(6);
  h.insert(7);

  h.print();

  return 0;
}