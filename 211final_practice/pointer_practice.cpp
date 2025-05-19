#include <iostream>

int main(){

    int a = 10;
     
    int *ip = &a;

    std::cout<<sizeof(a)<<"\n";//sizeof int is 4 bytes
    std:: cout<<sizeof(ip)<<"\n";//sizeof pointer is always 8 bytes on 64bit system
    std::cout<<sizeof(*ip);//sizeof dereferenced gets you the int again 

    return 0;
}