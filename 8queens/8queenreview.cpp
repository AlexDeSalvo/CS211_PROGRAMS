#include<iostream> 

using namespace std;



void rev_print(int n){
    
    //base case
    if(n/10 == 0){
        cout<<n%10;
        return;
    }   

    cout<<n%10;
    
    rev_print(n/10);
    
}



int main(){


    rev_print(12345);



    return 0; 
}