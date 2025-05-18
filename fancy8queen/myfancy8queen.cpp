//Author: Alexander DeSalvo

#include <iostream> 
#include <cmath> 
using namespace std;
//char(219) = white block
//char(179) = vertical line
//char(196) = horizontal line

//globally defining box type
typedef char box[5][8];
//structure for queen on white box
box bq = {{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                {char(219),' ',     char(219),' ',char(219),' ',        char(219)},
                {char(219),' ',     char(219),' ',char(219),' ',        char(219)},
                {char(219),' ',     ' ',      ' ',' ',      ' ',        char(219)},
                {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};
//structure for queen on black box
box wq = {{' ',' ',' ',' ',' ',' ',' '},
                {' ',char(219),' ',char(219),' ',char(219),' '},
                {' ',char(219),' ',char(219),' ',char(219),' '},
                {' ',char(219),char(219),char(219),char(219),char(219),' '},
                {' ',' ',' ',' ',' ',' ',' '}};

box bb,wb, *board[8][8];
//print function to print the current state of the board
void print(int state[]){

    //array state holds our entire solution set
    //state[i] represents what row a queen exists in, in column i

    static int solution_num = 0;
    
    //create black box and white box: 5x7 
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 7; j++){
            bb[i][j] = ' ';
            wb[i][j] = char(219);
        }
    }

    //fill board with alteranate positions 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if((i+j) % 2 == 0){
                board[i][j] = &wb;
            }else{
                board[i][j] = &bb;
            }
        }
    }

    //replace address with correct queens
    //board[state[i]][i] represents the [row][column] where a queen is
    for(int i = 0; i < 8; i++){
        //if placement of a queen is on an even spot
        //based upon row: state[i] and column i
        //we place a queen on black spot
        if((state[i]+i) % 2 == 0){
            board[state[i]][i] = &bq;
        }else{
            board[state[i]][i] = &wq;
        }
    }

    cout<<"Solution Number: "<<++solution_num<<endl;

    //print upper border
    for(int i = 0; i < 7*8; i++){
        cout<<"_";
    }
    cout<<endl;

    //print board
    for(int i = 0; i < 8; i++){
        for(int k = 0; k < 5; k++){
            //left border
            cout<<" "<<char(179);
            for(int j = 0; j < 8; j++){
                for(int l = 0; l < 7; l++){
                    cout<<(*board[i][j])[k][l];
                }
            }
            cout<<char(179)<<endl;
        }
        
    }

    //print bottom border
    for(int i = 0; i < 7*8; i++){
        cout<<char(196);
    }
    
    cout<<endl<<endl;


}

//ok function checks condition that we can place a queen at q[c]
bool ok(int state[], int c){
    //if queen already in that row then return false
    for(int i = 0; i < c; i++){
        if(state[i] == state[c]){
            return false;
        }
    }
    //Check for diagonal threat using absolute value
    for(int i = 0; i < c; i++){
        if(abs(c - i) == abs(state[c] - state[i])){
            return false;
        }
    }
    return true;

}

//backtrack function to dedrement c by 1
void backtrack(int &c){
    c--;
    if(c == -1){
        exit (0);
    }

}


int main(){

int q[8];
int c = 0;
q[0] = 0;

while(c >= 0){
    c++;
    if(c >= 8){
        print(q);
        backtrack(c);
    }else{
        q[c] = -1;
    }

    while(c >= 0){
        q[c]++;

        if(q[c] >= 8){
            backtrack(c);
        }else{
            if(ok(q,c)){
                break;
            }
        }

    }

}


}