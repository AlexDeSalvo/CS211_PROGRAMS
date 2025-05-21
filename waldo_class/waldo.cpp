#include <iostream>
#include <vector>

class waldo{
    //row and column represent the index of waldo in the matrix
    //value is the value of waldo in the matrix
    private: 
    int row;
    int col;
    int value;
   
    public:
    //default constructor 

    waldo(){
        row = 0; 
        col = 0;
    }

    //2 parameter constructor

    waldo(int i, int j){
        row = i;
        col = j;
    }

    //getters/setters

    void setRow(int r){
        row = r;
    }

    void setCol(int c){
        col = c;
    }

    void setValue(int v){
        value = v;
    }

    int getRow(){
        return row;
    }

    int getCol(){
        return col;
    }
   
    int getValue(){
        return value;
    }


    //overloaded operators

    waldo operator+(const waldo &w){
        waldo result;
        result.row = row + w.row;
        result.col = col + w.col;
        return result;
    }

    waldo operator-(const waldo &w){
        waldo result;
        result.row = row - w.row;
        result.col = col - w.col;
        return result;
    }

    waldo operator*(const waldo &w){
        waldo result;
        result.row = row * w.row;
        result.col = col * w.col;
        return result;
    }   


    waldo operator/(const waldo &w){
        waldo result;
        result.row = row / w.row;
        result.col = col / w.col;
        return result;
    }

    
    //a waldo is a value in a matrix that is the minimum in its row but max of its column
    waldo findWaldo(std::vector<std::vector<int>> &matrix){
        waldo result;
        int minRow = INT_MAX; // sets the minRow to the max value of int // smallest value in a row
        int maxCol = INT_MIN; // sets the maxCol to the min value of int // largest value in a column

        //find min in row
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] < minRow){
                    minRow = matrix[i][j];
                    result.setRow(i);
                    result.setCol(j);
                }
            }
        }

        //find max in a column
        for(int i = 0; i < matrix.size(); i++){
            if(matrix[i][result.getCol()] > maxCol){
                maxCol = matrix[i][result.getCol()];
                result.setRow(i);
            }
        }

        if(minRow == maxCol){
            result.setValue(matrix[result.getRow()][result.getCol()]);
            return result;
        }else {
            result.setRow(-1);
            result.setCol(-1);
            result.setValue(0);
            return result;
        }

    }

    
    //overloaded i/o operators

    friend std::ostream& operator<<(std::ostream &os, const waldo &w);
    friend std::istream& operator>>(std::istream &is, waldo &w);
};

int main(){

    std::vector<std::vector<int>> matrix = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3}
    };

    waldo w = w.findWaldo(matrix);

    std::cout<<w.getValue()<<std::endl;


    return 0;
}