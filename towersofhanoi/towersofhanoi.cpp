//Author Alexander DeSalvo
#include <iostream>
#include <vector>

//#define STOPLOOP

int main(){
    std::vector<int> t[3];
    int n;
    std::cout<<"Enter the number of rings to move: ";
    std::cin>>n;
    std::cout<<"\n";

    //intial value of to depends on whether n is odd or even
    int from_tower = 0;
    int candidate = 1;
    int move = 0;
    int to_tower = 1;
    //if n is even, the first to tower needs to be 2. 
    if(n % 2 == 0){
        to_tower = 2;
    }

    //intialize towers
    for(int i = n+1; i >= 1; i--){
        t[0].push_back(i);
    }
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    
    //start algorithm here: 
    while(t[1].size() < n+1){
        //make the first moves: 
        std::cout<<"Move "<<++move<<" : Transfer ring "<<candidate<<" from tower "<<char(from_tower+'A')<<" to tower "<<char(to_tower+'A')<<"\n";
        
        t[to_tower].push_back(candidate);
        t[from_tower].pop_back();
        
        //calculate from tower (find tower with next smallest ring)
        if(t[(to_tower+1)%3].back() > t[(to_tower+2)%3].back()){
            from_tower = (to_tower+2) % 3;
        }else from_tower = (to_tower+1) % 3;

        candidate = t[from_tower].back();
        
        //calculate to tower 
        if(candidate > t[(from_tower+1)%3].back()){
            to_tower = (from_tower + 2) % 3;
        }else to_tower = (from_tower + 1) % 3;

        //DEBUG STUFF
        // std::cout<<char(to_tower+'A')<<" "<<char(from_tower+'A')<<" "<<candidate;
        //stop loop macro for debug
        #ifdef STOPLOOP
        for(int i = n+1; i > 0; i--){
            t[1].resize(n+1);
        }
        #endif
    }

    std::cout<<"All rings moved to tower 2"<<"\n";

    return 0;
}
