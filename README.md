# advanced_assignment_06
Need to design two dimensional infinite sparse matrix filled with default value. The matrix must contain only occupied elements - the values of which have been assigned at least once. The assignment of the default value to matrix must free the matrix at given row and column. The matrix must have the features like returning its true size and iterating through its occupied elements. Accessing the free cell of the matrix should return the default value.


The following instantiations should work for the matrix: 


Matrix<int, -1> matrix;


assert(matrix.size() == 0); 


auto a = matrix[0][0];


assert(a == -1);


assert(matrix.size() == 0);


matrix[100][100] = 314;


assert(matrix[100][100] == 314);


assert(matrix.size() == 1);


for(auto c: matrix) {


int x, y, v;


std::tie(x, y, v) = c;


std::cout << x << y << v << std::endl; }
