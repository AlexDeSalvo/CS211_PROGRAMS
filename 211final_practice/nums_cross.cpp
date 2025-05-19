#include <iostream> 

using namespace std;


void print(int board[]){
   
   static int solution = 0;
   cout<<"Solution #: "<<++solution<<"\n";

    cout<<" "<<board[1]<<board[4]<<"\n";
    cout<<board[0]<<board[2]<<board[5]<<board[7]<<"\n";
    cout<<" "<<board[3]<<board[6]<<"\n";
}

void backtrack(int &col){
    col--;
    if(col == -1 ){
        exit(0);
    }
}

bool ok(int board[],int &col){

    //helper array tells you the index of the array you need to check difference of 1 against
    static int helper[8][5] = 
    {
        {-1},   //0
        {0,-1}, //1
        {0,1,-1},//2
        {0,2,-1},//3
        {1,2,-1},//4
        {1,2,3,4,-1},//5
        {2,3,5,-1},//6
        {4,5,6,-1},//7
    };

    for(int i = 0; i < col; i++){
        if(board[i] == board[col]) return false;
    }

    //tricky logic here worth noting
    //we take the col into our helper array to find the row the check values against
    //the values in that row iterated by i will return the adjecent boxes we need to check for 
    //a difference of 1 in our main array. 
    for(int i = 0; helper[col][i] != -1; i++){
        if(abs(board[helper[col][i]] - board[col]) == 1 ) return false;
    }

    return true;
}

int main(){
    int col = 0; 
    int board [8];
    board[col] = 1;

    while(col >= 0){
        col++;
        if(col >= 8){
            print(board);
            backtrack(col);
            
        }else board[col] = 0;

        while(col >= 0){
            board[col]++;

            if(board[col] > 8){
                backtrack(col);
            }else if(ok(board,col)){
                break;
            }
        }
    }


}