#include <iostream>

using namespace std;

class Rat{
    private:
    int n;
    int d;

    public:
    //default constructors 
    Rat(){
        n = 0;
        d = 1;
    }

    //2 parameter constructor

    Rat(int i, int j){
        n = i;
        d = j;
    }

    //copy constructor
    //takes a Rat as the argument to pass the values to the one being created
    Rat(const Rat &r){
        n=r.n;
        d=r.d;
    }

    //setters and getters

    void setN(int value){
        n = value;
    }

    void setD(int value){
        if(value <= 0){
            cout<<"Invalid value for Rat.D class"<<"\n";
        }
        d = value;
    }

    int getN(){return n;}
    int getD(){return d;}

    //overloaded operators

    Rat operator+(const Rat &r){
        Rat result;
        result.n = (n * r.d) + (r.n * d); 
        result.d = (d * r.d);
        return result;
    }

    Rat operator-(const Rat &r){
        Rat result;
        result.n = (n * r.d) - (r.n * d);
        result.d = (d * r.d);
        return result;
    }

    Rat operator*(const Rat &r){
        Rat result; 
        result.n = n * r.n;
        result.d = d * r.d;
        return result;
    }

    Rat operator-(const Rat &r){
        Rat result;
        result.n = d * r.n;
        result.d = n * r.d;
        return result;
    }

    //overloaded i/o operators

    friend ostream &operator<<(ostream &ostream, const Rat &r);
    friend istream &operator>>(istream &istream, Rat &r);

};

int main(){


    Rat r;
    
    r.setD(0);


}