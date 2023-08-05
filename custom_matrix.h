#include<iostream>
#include<unordered_map>


template<typename, int>
class RowProxy;

template<typename T>
class MatrixElement {

private:
    int row, col;
    T value;

public:
    MatrixElement(int row, int col, T value) : 
        row(row), col(col), value(value) {}

    T& getValue(){return value;}
};

template<typename T, int default_value>
class Matrix {

private:
    typedef std::hash<int> h;
    struct hash {
        std::size_t operator()(const std::pair<int, int> &p) const 
           { return h{}(p.first) ^ h{}(p.second); }
    };

    std::unordered_map<std::pair<int, int>, MatrixElement<T>*, hash> map;

public:

    MatrixElement<T>* getElement(int row, int col) {  
        std::pair<int, int> key(row, col);
        if (map.find(key) == map.end()) {
            MatrixElement<T>* element = new MatrixElement<T>(row, col, 0);
            map[key] = element;}

        return map[key];}

    RowProxy<T, default_value> operator[](const int&);

    size_t size(){return map.size();}

    bool findElement(int row, int col){
        std::pair<int, int> key(row, col);
        if (map.find(key) == map.end()){
            return false; }
        return true; }

    void display_notEmpty(){
        for(const auto& item : map){
            const std::pair<int, int>& key = item.first;
            MatrixElement<T>* el = item.second;
            std::cout << "matrix[" << key.first << "][" << key.second << "]: " << el->getValue() << std::endl; }
    }
};

template <typename T, int default_value>
class RowProxy { 
    private:
        int row;
        int column;
        Matrix<T, default_value>* matrix;

    public:
        RowProxy(int row, Matrix<T, default_value>* matrix) : row(row), matrix(matrix) {}

        RowProxy& operator[](const int& col){
            column = col;
            return *this; }

        void operator=(const T& value){
            auto el = matrix->getElement(row, column);
            el->getValue() = value; }

        bool operator==(const T& value){
            if(value == default_value){
                return default_value == value;}
            else{
            auto el = matrix->getElement(row, column);
            return el->getValue() == value; }
        }

        std::ostream& print(std::ostream& os) const{
            if(!matrix->findElement(row, column)){
                os << default_value; }
            else{
            os << matrix->getElement(row, column)->getValue();}
            return os; }
};

template<typename T, int default_value>
RowProxy<T, default_value> Matrix<T, default_value>::operator[](const int& row){
    return RowProxy<T, default_value>(row, this);}

template<typename T, int default_value>
std::ostream& operator<<(std::ostream& os, const RowProxy<T, default_value>& rowProxy){
    return rowProxy.print(os); }


