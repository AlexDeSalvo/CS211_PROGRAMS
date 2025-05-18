#include <iostream>
#include <vector>
//typedef for a new function pointer
typedef void(*helloworldfunc)();

typedef int(*arithmetic)(int a, int b);

void hello(){
   std::cout<<"Hello World";
}

int multiply(int a,int b){
    return a * b;
}

void PrintValue(int value){
    std::cout<<"Value: "<<value<<"\n";
}

//for each prototype contains the argument for the function pointer
void forEach(const std::vector<int> &values, void (*func)(int)){
    for(int it : values){
        func(it);
    }
}

int main(){

    //note functions are just CPU instructions 

    //this is what auto is doing for the fucntion pointer under the hood
    // return type on left, pointer name in first paranthesis and arguments in second.

    //because of the typedef you can now assing the function to a variable like so: 
    //function is a pointer to a function as described in the typedef 
    helloworldfunc function = hello;

    arithmetic mult = multiply;

    //can now use auto to point function to hello since calling just hello returns a pointer to that address of the function.
 

    std::vector<int> values = {1,2,3,4,5};

    //passing in the print value function as an argument 
    forEach(values,PrintValue);
    


return 0;


}