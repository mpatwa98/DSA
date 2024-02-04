#include <iostream>
using namespace std;

int add(int a, int b)
{
  int i = 1;
  while (b != 0)
  {
    cout << "loop = " << i << "\n";
    int carry = a & b; // Calculate the carry
    cout << carry << "\n";
    a = a ^ b; // Sum without considering the carry
    cout << a << "\n";
    b = carry << 1; // Left shift the carry to add it to the sum
    cout << b << "\n";
    i++;
  }
  return a;
}

int main()
{
  int num1, num2;
  cin >> num1 >> num2;
  cout << add(num1, num2) << std::endl;
  return 0;
}
