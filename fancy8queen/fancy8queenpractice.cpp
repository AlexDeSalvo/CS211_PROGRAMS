#include <iostream>

using namespace std;

typedef char box[5][7];

box bq = {{char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                {char(219),' ',     char(219),' ',char(219),' ',        char(219)},
                {char(219),' ',     char(219),' ',char(219),' ',        char(219)},
                {char(219),' ',     ' ',      ' ',' ',      ' ',        char(219)},
                {char(219),char(219),char(219),char(219),char(219),char(219),char(219)}};

box wq = {{' ',' ',' ',' ',' ',' ',' '},
            {' ',char(219),' ',char(219),' ',char(219),' '},
            {' ',char(219),' ',char(219),' ',char(219),' '},
            {' ',char(219),char(219),char(219),char(219),char(219),' '},
            {' ',' ',' ',' ',' ',' ',' '}};

box bb,wb, *board[8][8];

void print(int board[]){
    static int solution_num = 0;

    cout<<"Solution number: "<<++solution_num<<endl;

    for(int i = 0; i < 8; i++){
        
        for(int j = 0; j < 5; j++){
            
            for(int k = 0; k < 8; k++){
                
                for(int l = 0; l < 7; l++){
                    
                }
            }
        }
    }
}
void backtrack(int &c){
    c--;
    if(c <= -1){
        exit(0);
    }
}

bool ok(int board[], int c){

    for(int i = 0; i < c; i++){
        if(board[i] == board[c]){
            return false;
        }
    }

    for(int i = 0; i < c; i++){
        if(abs(c - i) == abs(board[c] - board[i])){
            return false;
        }
    }
    
    return true;


}

int main(){
    int board[8];
    int c = 0;
    board[c] = 0;

    while(c >= 0){
        c++;

        if(c >= 8){
            print(board);
            backtrack(c);
        }else{
            board[c] = -1;
        }

        while(c>=0){
            board[c]++;

            if(board[c] >= 8){
                backtrack(c);
            }else{
                if(ok(board,c)){
                    break;
                }
            }
        }
    }




    return 0;
}