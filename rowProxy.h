#pragma once
#include "matrix.h"

template<typename T, T default_value>
class Matrix;

template <typename T, T default_value>
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
            
        	if(value == default_value){
                if(matrix->getElement(row, column) != default_value){
        			matrix->deleteElement(row, column); }
        		else{return;}
        	}

        	else{matrix->addElement(row, column, value); }
        }

        bool operator==(const T& value){
            if(value == default_value){
                return default_value == value;}
            else{
            T el = matrix->getElement(row, column);
            return el == value; }
        }

         std::ostream& print(std::ostream& os) const{
            T val = matrix->getElement(row, column);
            if(val == default_value){os << default_value;}
            else{os << val;}
            return os; }
};

template<typename T, T default_value>
std::ostream& operator<<(std::ostream& os, const RowProxy<T, default_value>& rowProxy){
    return rowProxy.print(os); }

