#include <cassert>
#include "custom_matrix.h"

int main() {

    Matrix<int, 0> matrix;
    assert(matrix.size() == 0);

    auto a = matrix[0][0];
    assert(a == 0);
    assert(matrix.size() == 0);

    for(int i=0; i<10; i++){
        matrix[i][i] = i;
        matrix[i][9-i] = 9-i; }

    std::cout << "  ";
    for(int i=1; i<9; i++){
        for(int j=0; j<10; j++){
            if((i==1 && j==0) || (i==8 && j==9)) continue;
        std::cout << matrix[i][j] << " "; }
        std::cout << std::endl;
    }

    matrix.display_notEmpty();

    std::cout << "Matrix size: " << matrix.size() << std::endl;
}