#include <cassert>
#include "matrix.h"

int main() {
    
    Matrix<int, 0> matrix;

    assert(matrix.size() == 0);
    auto a = matrix[0][0];

    
    assert(a == 0);
    assert(matrix.size() == 0);
    matrix[100][100] = 314;
    assert(matrix[100][100] == 314);
    assert(matrix.size() == 1);
    matrix[100][100] = 0;
    assert(matrix[100][100] == 0);
    assert(matrix.size() == 0);


    for (auto i = 0; i < 10; i++)
        matrix[i][i] = i;
    for (auto i = 0, j = 9; i < 10; i++, j--)
        matrix[i][j] = j;

    std::cout<<"size: "<<matrix.size()<<std::endl;

    for(auto c : matrix){
        int x,y,v;
        std::tie(x, y, v) = c;
        std::cout<<"["<<x<<"]"<<"["<<y<<"]"<<" value: "<<v<< std::endl;
    }

    for(auto i = 1; i < 9; i++){
        for (auto j = 1; j < 9; j++){
            std::cout<<matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
    
}