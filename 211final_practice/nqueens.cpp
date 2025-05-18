#include <iostream> 

using namespace std;



void backtrack(int &col){
    col--;

}


bool ok(int board[], int col){

    for(int i = 0; i < col; i++){
        if(board[i] == board[col] || abs(col - i) == abs(board[col] - board[i])) return false;
    }

    return true;
}

int nqueens(int n){
    
    static int solutions = 0;
    int *board = new int [n];
    int col = 0;

    board[col] = 0; 

    while(col >= 0){
        col++;
        if(col >= n){
            ++solutions;
            backtrack(col);
            if(col == -1){
                delete[] board;
                return solutions;
            }
        }else board[col] = -1;

        while(col>=0){
            board[col]++;
            
            if(board[col] >= n){
                backtrack(col);
            
            }else if(ok(board,col)) break;

            
        }
    }

    delete[] board;
    return solutions;

}






int main(){

    int n; 
    cout<<"Enter size of board: ";
    cin>>n;

    cout<<"There are "<<nqueens(n)<<" Solutions";



    return 0;
}