#include <iostream>
#include <math.h>
// author : Alexander DeSalvo

using namespace std;
// constand variables for max row and column

int main()
{
    // declare and initialize 1d array
    int board[8];
    
    //variable for row and columns
    int c = 0;


    // place first queen
    board[0] = 0;

    // label for next column

nc:
    c++;
    if (c == 8){
        goto print;
    }
    // row needs to be initialized to -1 so when we jump to
    // next row we start from 0, as the nr functions starts with r++//
    board[c] = -1;

    // label for next row
nr:
    board[c]++;

    if (board[c] == 8)
    {
        // if no suitable place in this column, we need to backtrack previous column.
        goto backtrack;
    }

    //combine row and diagonal tests
    for(int i = 0; i < c; i++){
        //if board sub i is equal to board sub c then new row
        //if the difference in c - i is equal to absolute value of values in the array the space is no good
        if(board[i] == board[c] || c - i == abs(board[c]-board[i])){
            goto nr;
        }
    }


    goto nc;

// backtrack label
backtrack:
    c--;
    if (c == -1){
        return 0;
    }

    //go to next row to find a new suitable place for queen
    goto nr;


// label for print
print:
    // static variable for num of solutions
    static int numSolutions = 0;
    cout << "Solution # " << ++numSolutions << endl;

    //row loop
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[j] == i){
                cout<<"1"<<" ";
            }else cout<<"0"<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    goto backtrack;
}