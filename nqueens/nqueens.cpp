#include <iostream>

using namespace std;

int backtrack(int &c)
{
    c--;
    if (c == -1)
    {
        return 0;
    }
    return 1;
}

bool ok(int board[], int c)
{
    for (int i = 0; i < c; i++)
    {
        if ((board[i] == board[c]) || abs(c - i) == abs(board[c] - board[i]))
        {
            return false;
        }
    }
    return true;
}

// print fc not used
void print(int board[])
{

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i] == j)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        cout << "\n";
    }
}

int nqueens(int n)
{
    static int solutions = 0;
    int *board = new int[n];
    int c = 0;
    board[c] = 0;

    while (c >= 0)
    {
        c++;
        if (c >= n)
        {
            solutions++;
            // print
            if (backtrack(c) == 0)
            {
                delete[] board;
                return solutions;
            }
        }
        else
        {
            board[c] = -1;
        }

        while (c >= 0)
        {
            board[c]++;
            if (board[c] >= n)
            {
                backtrack(c);
            }
            else if (ok(board, c))
            {
                break;
            }
        }
    }

    delete[] board;

    return solutions;
}

int main()
{

    int n = 0;
    cout << "Board size? ";
    cin >> n;

    cout << nqueens(n) << " Solutions";

    return 0;
}