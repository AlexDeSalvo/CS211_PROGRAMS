#include <iostream>
#include <float.h>



int main(){

    char op;
    double a, b, res;

    std::cout<<"Enter an operator ";
    std::cin>>op;

    std::cout<<"Enter two numbers ";
    std::cin>>a>>b;

    switch(op){
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': res = a / b; break;
        
        default: std::cout<<"Error! Operator is not correct";
        res = -DBL_MAX;
    }

    if(res != -DBL_MAX){
        std::cout<<"Result "<<res;
    }

    return 0;
}