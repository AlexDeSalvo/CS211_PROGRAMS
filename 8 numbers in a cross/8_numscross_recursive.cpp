#include <iostream>
#include <math.h>

using namespace std;

//print prototype to silence scope error
void print(int q[]);

bool ok(int q[], int c){

    //helper array for what blocks to check in q. 
    // c gives us the row and i will give us box values to check. 
    static int avoid[8][5] = 
        {{-1}, //row 0
         {0,-1}, //row 1
         {0,1,-1}, //row 2
         {0,2,-1}, // row 3
         {1,2,-1}, //row 4
         {1,2,3,4,-1}, //row 5
         {2,3,5,-1}, // row 6
         {4,5,6,-1} //row 7
        };
    
        //check if # has been used
    for(int i = 0; i < c; i++){
        if(q[i] == q[c]){
            return false;
        }
    }

    for(int i = 0; avoid[c][i] != -1; i++){
        if(abs(q[c] - q[avoid[c][i]]) == 1){
             return false;
        } 
    }

    return true;

}


void next(int q[], int c){
    if (c == 8){
        print(q);
    }else for(q[c] = 1; q[c] <= 8; ++q[c]){
        if(ok(q,c)){
            next(q,c+1);
        }
    }

}

void print(int q[]){
    static int solution = 0; 
    cout<<"Solution #"<< ++solution<<"\n";
    cout<<" "<<q[1]<<q[4]<<"\n";
    cout<<q[0]<<q[2]<<q[5]<<q[7]<<"\n";
    cout<<" "<<q[3]<<q[6]<<" "<<"\n";

}


int main(){

    int q[8];

    next(q,0);
    

    return 0;
}