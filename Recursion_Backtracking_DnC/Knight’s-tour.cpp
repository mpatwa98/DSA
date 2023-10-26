#include <bits/stdc++.h>
using namespace std;
const int n = 8;
// TC = 8^n*n;
// SC = n*n;

void printSolution(vector<vector<int>> &sol)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << " " << setw(2) << sol[i][j] << " ";
    }
    cout << "\n";
  }
}

bool isValid(int x, int y, vector<vector<int>> &sol)
{
  return (x >= 0 && x < n && y >= 0 && y < n && sol[x][y] == -1);
}

int solveKTUtil(int x, int y, int steps, vector<vector<int>> &sol, int dx[], int dy[])
{
  if (steps == n * n)
  {
    return 1;
  }
  for (int k = 0; k < 8; k++)
  {
    int newx = x + dx[k];
    int newy = y + dy[k];
    if (isValid(newx, newy, sol))
    {
      sol[newx][newy] = steps;
      if (solveKTUtil(newx, newy, steps + 1, sol, dx, dy))
      {
        return 1;
      }
      else
      {
        sol[newx][newy] = -1;
      }
    }
  }

  return 0;
}

void solveKT()
{
  // for storing the answer
  vector<vector<int>> sol(n, vector<int>(n, -1));
  int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
  int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
  sol[0][0] = 0;
  if (!solveKTUtil(0, 0, 1, sol, dx, dy))
  {
    cout << "No Solution exists!!!\n";
  }
  else
  {
    printSolution(sol);
  }
}

int main()
{
  solveKT();

  return 0;
}