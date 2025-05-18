#include <iostream> 
using namespace std;


int main(){

    int q[3];
    for(int i0 = 0; i0<3; i0++){
        for(int i1=0; i1<3;i1++){
            for(int i2=0; i2<3; i2++){

                q[0] = i0;
                q[1] = i1;
                q[2] = i2;
                for(int k = 0; k < 3; k++){
                    cout<<q[k]<<'\t';
                    cout<<endl;
                }
            }
        }
    }

}