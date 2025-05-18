#include <iostream> 
#include <cmath>
using namespace std;



int main(){

//char(219) = white bloack
//char(179) = vertical line
//char(196) = horizontal line

typedef char box[5][8];

int i,j,k,l;

box bb,wb,*board[8][8];

//fill boxes:
for(int i = 0; i < 5; i++){
    for(int j = 0; j < 7; j++){
        wb[i][j] = ' ';
        bb[i][j] = char(219);//WHITE BLOCK 
    }
}

//fill board with alternate positions
for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
        if((i+j) % 2 == 0){
            board[i][j] = &wb;//inverted because it should be black on even numbers
        }else{
            board[i][j] = &bb;
        }
    }
}

//print upper border 
cout<<" ";
for(int i = 0; i < 7 * 8; i++){
    cout<<"_";
}
cout<<endl;

//print the board
for(i = 0; i < 8; i++){
    for(k = 0; k < 5; k++ ){
        //left border
        cout<<" "<<char(179);
        for(j = 0; j <8; j++){
            for(l = 0; l < 7; l++){
                cout<<(*board[i][j])[k][l];
            }
        }
        //right border
        cout<<char(179)<<endl;
    }
}

//print lower border before exiting
cout<<" ";
for(int i = 0; i < 7*8; i++){
    cout<<char(196);
}

cout<<endl<<endl;


    return 0;
}