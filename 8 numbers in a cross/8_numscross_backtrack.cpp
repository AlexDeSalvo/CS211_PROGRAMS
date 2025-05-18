#include <iostream>
#include <math.h>

using namespace std;
// board where values for cross are stored
int q[8];

// function prototypes
void print(int q[]);
void backtrack(int &c);
bool ok(int q[], int c);

// backtrack function to decrement which box we are working with
void backtrack(int &c)
{

    c--;

    if (c <= -1)
    {
        exit(0);
    }
}

// Error check function to see if we can place a number
bool ok(int q[], int c)
{

    // helper array for what blocks to check in q.
    //  c gives us the row and i will give us box values to check.
    static int avoid[8][5] =
        {
            {-1},             // row 0
            {0, -1},          // row 1
            {0, 1, -1},       // row 2
            {0, 2, -1},       // row 3
            {1, 2, -1},       // row 4
            {1, 2, 3, 4, -1}, // row 5
            {2, 3, 5, -1},    // row 6
            {4, 5, 6, -1}     // row 7
        };

    // check if # has been used
    for (int i = 0; i < c; i++)
    {
        if (q[i] == q[c])
        {
            return false;
        }
    }

    // check values in boxes provided by helper array that the difference is not greater than 1
    for (int i = 0; avoid[c][i] != -1; i++)
    {
        if (abs(q[c] - q[avoid[c][i]]) == 1)
        {
            return false;
        }
    }

    return true;
}

// prints array and counts solutions
void print(int q[])
{

    static int solution = 0;
    cout << "Solution #" << ++solution << "\n";
    cout << " " << q[1] << q[4] << "\n";
    cout << q[0] << q[2] << q[5] << q[7] << "\n";
    cout << " " << q[3] << q[6] << " " << "\n";
}

int main()
{
    // initialize array to 0s;
    int q[8] = {0};
    int c = 0;
    // first box set to 1
    q[c] = 1;

    // while loop to keep the algorithm going until backtrack reached c = -1
    while (c >= 0)
    {
        c++;
        // if we reach the end, print the solution then backtrack for more solutions
        if (c >= 8)
        {
            print(q);
            backtrack(c);
            // if we arent at the end set the value of this box to 0
        }
        else
            q[c] = 0;

        // while the value is greater or equal to 0, check that a number can be placed
        while (q[c] >= 0)
        {

            q[c]++;
            // if we have reached 9 then a number cannot be placed here and we must go backwards to find our issue
            if (q[c] == 9)
            {
                backtrack(c);
                // if we haven't reached 9 check that it is ok to place
            }
            else if (ok(q, c))
            {
                break;
            }
        }
    }

    return 0;
}