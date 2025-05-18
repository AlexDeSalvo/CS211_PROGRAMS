#include <iostream>
#include <vector>

int main(){

    //empty vector of size 0 (run time data structure)
    std::vector<int> v1;

    //{} braces gives you list initialization
    std::vector<int> v2 {5,12};
    //() gives you size 12, all initialized to 5
    std::vector<int> v3 (12,5);

    //pushback will add an element to back of vector = good for ordered lists
    for(int i = 0; i <= 5; i++){
        v1.push_back(i);
    }

    //can access vector indices using [] or () but the braces will allow you to go out of bounds. 
    //safer to use v1.at(3) for example: 

    std::cout<< v1.at(3)<<"\n"; //outputs 3 since we iterate from 0. 

    for(auto &i : v1) std::cout<<i;

    std::cout<<"\n";

    for(auto &i : v2) std::cout<<i;

    std::cout<<"\n";

    for(auto &i : v3) std::cout<<i;
    std::cout<<"\n";

    //you can erase elements from back of a vector using pop_back
    v1.pop_back();
    for(auto &i : v1) std::cout << i; //5 is now erased from end of the vector
    //you can also use the vector erase() function with vector find() to find an erase a certain element
    //find takes arguments of where to begin search, where to end and what to delete. 
    v1.erase(find(v1.begin(),v1.end(),2));

    v1.size(); // returns number of elements in vector

    v1.empty();//checks if vector is empty

    v1.front(); //access front of vector, v1.back() does the back 

    v1.insert(v1.begin(),8);//takes two arguments, iterator of where to insert and a value to insert

    
    return 0;
}