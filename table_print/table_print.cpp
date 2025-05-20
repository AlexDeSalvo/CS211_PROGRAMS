#include <iostream>

using namespace std;


void table_print(int arr[],int size, int col, int row){

    if(col * row != size){
        cout<<"Cannot be done";
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout<<arr[i * col + j]<<" ";
        }
        cout<<"\n";
    }

}


int main(){

    int arr [6] = {10,20,30,40,50,60};

    table_print(arr,6,3,2);



}