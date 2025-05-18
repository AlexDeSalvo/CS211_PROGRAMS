#include <iostream>
#include <vector>


unsigned int fib(int n){
    static std::vector<unsigned int> memo;
    
    if(n == 0 || n == 1){
        return 1;
    }
    if(n >= memo.size()){
        memo.resize(n+1,0);
    }
    
    if(memo[n] != 0){
        return memo[n];
    }

    return memo[n] = fib(n-1) + fib(n-2);
}


int main(){
    int n;
    std::cout<<"Enter fibonacci number to solve: ";
    std::cin>>n;

    std::cout<<"Fibonacci "<<n<<" is "<<fib(n);


    return 0;
}