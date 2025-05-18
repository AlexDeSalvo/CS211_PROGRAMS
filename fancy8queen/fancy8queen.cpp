#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int col){
	for(int i=0; i<col; i++){
		if((q[i]==q[col]) || ((col-i)==abs(q[col]-q[i]))){ 
			return false;
		}
	}
	return true;	
}

void print(int q[]){
	static int numSolutions=0;
	int i, j, k, l;
	typedef char box[5][7];
	box bb, wb, *board[8][8];
	
	//create the blackbox and the white box 
	for(int i=0; i<5; i++){
		for(int j=0; j<7; j++){
			bb[i][j]=' ';
			wb[i][j]=char(219);
		}
	}
	
	//two more boxes for white queen and black queen
   static box bq = { {char(219),char(219),char(219),char(219),char(219),char(219),char(219)},
                     {char(219),' '      ,char(219),' '      ,char(219),' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),' '      ,' '      ,' '      ,' '      ,' '      ,char(219)},
                     {char(219),char(219),char(219),char(219),char(219),char(219),char(219)} };
               
 
   static box wq = { {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      },
                     {' '      ,char(219),' '      ,char(219),' '      ,char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,char(219),char(219),char(219),char(219),char(219),' '      },
                     {' '      ,' '      ,' '      ,' '      ,' '      ,' '      ,' '      } };
                     
	//fill in the boxes with alternate positions
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if((i+j)%2==0){
				board[i][j]= &wb;
			}
			else{
				board[i][j]= &bb;
			}
		}
	}    
	
	///replacing the addresses with the appropriate queens 
	for(int i=0; i<8; i++){
		if((q[i]+i)%2==0){
			board[q[i]][i]=&bq;
		}
		else{
			board[q[i]][i]=&wq;
		}
	}
	
	cout<<"Solution Number "<< ++numSolutions << " :"<<endl;
	
	//upper border
	for(int i=0; i<7*8; i++){
		cout<<"_";
	}
	cout<<endl;
	
	//board portion
	for(int i=0; i<8; i++){
		for(int k=0; k<5; k++){
			//left border
			cout<<" "<<char(179);
			for(int j=0; j<8; j++){
				for(int l=0; l<7; l++){
					cout<<(*board[i][j])[k][l];
				}
			}
			cout<<char(179)<<endl;
		}
	}

	//print lower border
	cout<<" ";
	for(int i=0; i<7*8; i++){
		cout<<char(196);
	}
	cout<<endl<<endl;		
}

void backtrack(int &col){ 
	col--;
	
	if(col==-1){
		exit(0); 
	}
}

int main(){
	int q[8];
	int col=0;
	q[0]=0;

	while(col>=0){
		col++;
			
		if(col==8){
			print(q);
			backtrack(col);
		}
		else{
			q[col]=-1;	
		}
	
		while(col>=0){
			q[col]++;
			
			if(q[col]==8){
				backtrack(col);
			}
			else{
				if(ok(q,col)==true){
					break;
				}
			}
			
		}
	}
}

