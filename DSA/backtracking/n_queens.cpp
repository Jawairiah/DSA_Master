#include <iostream>
using namespace std;
bool isSafe(int x, int y, int n, int **arr)
{
    for (int row = 0; row < x; row++)
    {
        if (arr[row][y] == 1)
        {
            return false;
        }
    }
    int row = x, col = y;
    while (row >= 0 && col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = x, col = y;
    while (row >= 0 && col < n)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
    return true;
}
bool nQueens(int x, int n, int **arr)
{
    if (x >= n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(x, i, n, arr))
        {
            arr[x][i] = 1;

            if (nQueens(x + 1, n, arr))
            {
                return true;
            }

            arr[x][i] = 0;
        }
    }
    return false;
}
int main()
{
    int **arr = new int *[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = new int[4];
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            arr[i][j]=0;
        }
    }
    nQueens(0,4,arr);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}