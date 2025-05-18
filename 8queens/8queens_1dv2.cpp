#include <iostream> 
#include <cmath>

using namespace std;


bool ok(int &c, int q[]){

    //check to see if row and diagonals are good
    //if the value in q[i] == q[c] then there exists a queen in that row
    //if the absolute difference of c - i is equal to the absolute difference in q[c] - q[i] there is a diagonal threat
    //
    for(int i = 0; i < c; i++){
        if(q[i] == q[c] || c - i == abs(q[c] - q[i])){
            return false;
        }else return true;
        
    }
}

void print(int q[]){
    static int solution_num = 0; 
    cout<<"Solution #: "<<++solution_num<<"\n";

    //row loop
    for(int i = 0; i < 8; i++){
        //column loop
        for(int j = 0; j < 8; j++){
            if(q[j] == i){
                cout<<"1"<<" ";
            }else {
                cout<<"0"<<" ";
            }
        }
        cout<<"\n";
    }

}

void backtrack(int &c){
    c--;
    if(c == -1){
        exit(0);
    }
}


int main(){
    //intialize board to all 0s 
    int q[8] = {0};
    //intialize current column to 0
    int c = 0;
    //place first queen (row that column has a queen in)
    q[c] = 0;
    //loop to keep columns algorithm going 
    while(c >= 0){
        c++;

        if(c == 8){
            print(q);
            backtrack(c);
        }else{
            //resets to -1 even after a backtrack
            q[c] = -1;
        }
        //loop to keep our rows algorithm going 
        while(c >= 0){
            q[c]++;
            
            if(q[c] >= 8){
                backtrack(c);
            }

            if(ok(c,q)){
                break;
            }
        }
    }
}