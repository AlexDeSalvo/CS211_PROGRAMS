#include <iostream>
#include <vector> 



int main(){
    //3 vectors represent our poles stored in an array of vectors
    //n+1 disks all on first vector
    //all others initialized to n+1 as only value 
    //int variable to represent move_from, move_to, candidate, move (move counter)

    //if the n is odd our first pole is t[1] else our fist pole is tower[2].

    int move_from = 0;
    int move_to = 1;
    int move = 0;
    int candidate; 
    int n;
    std::vector<int> t[3];

    std::cout<<"How many disks? ";
    std::cin>>n;

    if(n % 2 == 0){
        move_to = 2;
    }

    //vectors initialized
    for(int i = n+1; i > 0; i--){
        t[0].push_back(i);
    }
    t[1].push_back(n+1);
    t[2].push_back(n+1);

    candidate = t[move_from].back();
    //while the 2nd tower size is less then n+1 we keep running 
    while(t[1].size()<n+1){

        std::cout<<"Move: "<<++move<<" Disk "<<candidate<<" From tower "<<char(move_from + 'A')<<" to "<<char(move_to+'A')<<"\n";
        
        //make first move here
        t[move_to].push_back(candidate);
        t[move_from].pop_back();
        
        //arithmetic to determine next move_from: 
        // closest tower that has the smallest value on top that insnt the move to tower
        if(t[(move_to + 1) % 3].back() > t[(move_to+2) % 3].back()){
            move_from = (move_to + 2) % 3;
        }else move_from = (move_to + 1) % 3;

        candidate = t[move_from].back();
       
        //arithmetic to determine next to_tower:
        if(candidate > t[(move_from+1)%3].back()){
            move_to = (move_from + 2) % 3;
        }else move_to = (move_from + 1) %3;

    }

}