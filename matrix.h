#pragma once 
#include<iostream>
#include<unordered_map>
#include "rowProxy.h"


template<typename T, T default_value>
class Matrix {

private:

    typedef std::hash<int> h;
    struct hash {
        std::size_t operator()(const std::pair<int, int> &p) const 
           { return h{}(p.first) ^ h{}(p.second); }
    };

    std::unordered_map<std::pair<int, int>, T, hash> map;
    using Iter = typename std::unordered_map<std::pair<int, int>, T, hash>::iterator;

public:

    size_t size(){return map.size();}

    RowProxy<T, default_value> operator[](const int& row){
       return RowProxy<T, default_value>(row, this); }

    void addElement(int row, int col, T element){
        std::pair<int, int> key(row, col);
        map.insert(std::make_pair(key, element)); }

    void deleteElement(int row, int col){
        std::pair<int, int> key(row, col);
        map.erase(key); }

     T getElement(int row, int col){
        std::pair<int, int> key(row, col);
        auto iter = map.find(key);
        if(iter == map.end()){return default_value;}
        return iter->second;;}

    class Iterator{
    public:
        Iterator(Iter  matrixIt_):iterator(matrixIt_){};
        
        Iter getInsideIterator(){
            return this->iterator; } 
        
        void operator++(){
            iterator++; };
        
        std::tuple<int, int, T> operator*(){
            return std::make_tuple(iterator->first.first, iterator->first.second, iterator->second); };
        
        void operator--(){
            iterator--; }
        
        bool operator !=(Iterator& other){
            return iterator != other.getInsideIterator();}
        
        bool operator ==(Iterator& other){
            return iterator == other.getInsideIterator();}
        
    private:
        Iter  iterator;
    };
    
    
    Iterator begin(){
        return Iterator(map.begin()); };
    
    Iterator end(){
        return Iterator(map.end()); };

};


 