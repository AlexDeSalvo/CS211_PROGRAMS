#include <iostream>

using namespace std;




bool ok(int board[],int &col){

    for(int i = 0; i < col; i++){
        if(board[i] == board[col]) return false;
    }

    for(int i = 0; i < col; i++){
        if(abs(col - i) == abs(board[i] - board[col])) return false;
    }

    return true;
}

void backtrack(int &col){
    col--;
}


int nqueen(int n){
    int numSolutions = 0;
    int *board = new int [n];
    int col = 0; 

    board[col] = 0;

    while(col >= 0){
        col++;
        if(col >= n){
            numSolutions++;
            backtrack(col);
            if(col == -1){
                delete[] board;
                return numSolutions;
            }
        }else{
        board[col] = -1;
        }

        while(col >= 0){
            board[col]++;
            if(board[col] >= n){
                backtrack(col);
            }else if(ok(board,col)){
                break;
            }

            
        }
    }

    delete[] board;
    return numSolutions;
}




int main(){
    
    int n; 
    cout<<"Enter size of your board ";
    cin>>n;

    cout<<"There are "<<nqueen(n)<<" solutions.";
    
    
    
    return 0;
}