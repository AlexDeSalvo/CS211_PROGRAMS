#include <iostream> 

using namespace std;


bool ok(int q[],int col){

    int mp [3][3]{
        {0,2,1},
        {0,2,1},
        {1,2,0},
    };
    int wp[3][3]{
        {2,1,0},
        {0,1,2},
        {2,0,1}
    };

    //check to make sure match hasnt been made
    for(int i = 0; i < col; i++){
        if(q[i] == q[col]) return false;
    }

    
    for(int i = 0; i < col; i++){
        //if man i prefers the current mans wife over his own and 
        //if the current mans wife also man i over her own husband
        //(man i preference checked against current mans wifes preference)     
        if((mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col]) ||
            //if the current man prefers man i's wife over his own and if 
            //man i's wife prefers the current man over her own
            mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i] ) return false;
    }

    return true;

}

void backtrack(int &col){
    col--;
    if(col == -1){
        exit(0);
    }
}

void print(int board[]){
    static int solution;
    cout<<"Solution #: "<<++solution<<"\n";
    cout<<"man\twoman"<<"\n";
    
    for(int i = 0; i < 3; i++){
        cout<<i<<"\t"<<board[i]<<"\n";
    }

    cout<<"\n";
}

int main(){
    int col = 0; 
    int board[3];
    
    board[col] = 0;

    while(col >= 0){
        col++;
        if(col > 2){
            print(board);
            backtrack(col);
        }else board[col] = -1;

        while(col >= 0){
            board[col]++;

            if(board[col] > 2){
                backtrack(col);
            }else if(ok(board,col)){
                break;
            }
        }
    }

}