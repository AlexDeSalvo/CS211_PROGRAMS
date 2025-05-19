#include <iostream>

using namespace std;

int main(){

    int a = 10;
     
    int *ip = &a;
    
    cout<<"sizeof with pointers and ints"<<"\n";

    std::cout<<sizeof(a)<<"\n";//sizeof int is 4 bytes
    std:: cout<<sizeof(ip)<<"\n";//sizeof pointer is always 8 bytes on 64bit system
    std::cout<<sizeof(*ip)<<"\n";//sizeof dereferenced gets you the int again 

    cout<<"sizeof with char arrays"<<endl;

    char b[2][3];

    cout<<sizeof(b)<<"\n";//will give us size of entire array of chars = 6
    cout<<sizeof(*b)<<"\n";//will give sizeof the first row of array, accessing the contiguous memory without a index specifier = 3
    cout<<sizeof (*(b+0))<<"\n";//will give us sizeof the first row also = 3
    cout<<sizeof(*(*b+0))<<"\n"; //will give us the size of the first element in the first row = 1
    cout<<sizeof(*(b))<<"\n";// will also give us the entire first row. 

    cout<<"sizeof with *array* of *pointers - important distinction"<<"\n";

    int *c [2][3];

    cout<<sizeof(c)<<"\n";//will give us size of entire array of pointers which is 48 since int pointer is 8 bytes on 64 bit
    cout<<sizeof(*c)<<"\n";//will give us size of first row of the array of pointers which is 24 since 8 * 3 = 24
    cout<<sizeof(*(c+0))<<"\n";//should also give us size of firs row of the array = 24
    cout<<sizeof(*(*c+0))<<"\n";//should give us size of pointer in the pointer array which is 8.
    cout<<sizeof(*(c))<<"\n";//should also give us size of first row
    return 0;
}