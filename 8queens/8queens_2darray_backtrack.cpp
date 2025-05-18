#include <iostream> 

using namespace std;
const int MAXCOL = 8;
const int MAXROW = 8;

int main(){

    int board[8][8];
    int column = 0;
    int row = 0;

    //set board all 0;

    for(int i = 0; i < MAXROW; i++){

        for(int j = 0; j < MAXCOL; j++){
            board[i][j] = 0;
        }
    }

    //Place first queen
    
    board[0][0] = 1;

//new column label
nc: 
    column++;
    
    if(column == 8){
        goto print;
    }

    row = -1;

//new row label
nr: 
    row++;
    if(row == 8){
        goto backtrack;
    }

    //check across row for a queen
    for(int i = 0; i < column; i++){
        if(board[row][i]== 1){
            goto nr;
        }
    }

    //check up diagonal 
    for(int i = 1; ((row - i) >= 0 && (column - i) >= 0); i++){
        if(board[row - i][column-i]==1){
            goto nr;
        }
    }


    //check down diagonal for a queen; 
    for(int i = 1; ((row + i) <= 7 && (column - i) >= 0); i++){
        if(board[row+i][column-i] == 1){
            goto nr;
        }
    }

    //passed all tests so place the queen 
    board[row][column]= 1;

    goto nc;


backtrack: 

    column--;
    if(column == -1){
        return 0;
    }

    row = 0;

    while(board[row][column]!= 1){
        row++;
    }

    board[row][column] = 0;

    goto nr;

print: 

    static int numsolutions = 0;
    
    cout<<"Solution # "<<++numsolutions<<endl;

    for(int i = 0; i < MAXROW; i++){
        for (int j = 0; j < MAXCOL; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }

    goto backtrack;
    
}