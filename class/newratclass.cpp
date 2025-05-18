//Author: Alexander DeSalvo
#include <iostream> 


using namespace std;

class Rat{
    private:
   
    int n;
    int d;

    public:
    //default constructor 
    Rat(){
        n = 0;
        d = 1;
    }

    //2 parameter constructor 
    Rat(int i,int j){
        n=i;
        d=j;
    }

    //conversion constructor
    Rat(int i){
        n=i;
        d=1;
    }

    //access functions

    int getN(){return n;}
    int getD(){return d;}

    void setN(int i){n = i;}
    void setD(int i){d = i;}

    //reduction function 
    void reduce(){
        int a = abs(n);
        int b = abs(d);
        //find gcd using euclidean 
        while(b != 0){
            int temp = b;
            b = a % b;
            a = temp;
        }

        int gcd = a;
        n /= gcd;
        d /= gcd; 

        if(d<0){
            d = -d;
            n = -d;
        }

    }

    //arithmetic operators
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

    Rat operator/(const Rat &r){
        Rat result;
        result.n = n * r.d;
        result.d = n * r.n;

        return result;
    }

    //overloaded i/o operators

    friend ostream& operator<<(ostream &os,const Rat& r);
    friend istream& operator>>(istream &is,Rat& r);

    //output function: 
    void print(){
        reduce();
        if(n >= d){
            int whole_num = n/d;
            int remainder = n % d;

            if(remainder == 0){
                std::cout<<whole_num;
            }else{
                cout<<whole_num<<" "<<remainder<<"/"<<d;
            }
        }else{
            cout<<n<<"/"<<d;
        }
    }
};


int main(){


    return 0;
}