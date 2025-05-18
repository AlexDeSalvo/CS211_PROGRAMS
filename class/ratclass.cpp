#include <iostream>

using namespace std;


class Rat{

    private:
    int n;
    int d;

    public:
    //constructors 

    //default
    Rat(){
        n = 0;
        d = 1;
    }
    //2 parameter constructor
    Rat(int i, int j){
        n = i;
        d = j;
    }

    //conversion constructor
    Rat(int i){
        n = i;
        d = 1;
    }

    //access functions

    int getN(){
        return n;
    }
    int getD(){
        return d;
    }
    void setN(int i){
        n = i;
    }
    void setD(int i){
        d = i;
    }

    //addition function

    Rat operator+(Rat r){
        Rat t;
        t.n = n * r.d + d * r.n;
        t.d = d * r.d;

        return t;
    }

    // i/o operators, overloaded to write to input and output stream
    //friend lets us access the private data in a class

    friend ostream& operator<<(ostream&os,const Rat r);
    friend istream& operator>>(istream&is, Rat& r);

    //could also use getN or getD here instead of friend to access the data as those
    //are parts of the public members. 
};

int main(){
    return 0;
}