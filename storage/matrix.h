#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <initializer_list>
#include <math.h>
#include "MathVector.h"

using namespace std;

template <typename T>
class Matrix{
    private:
    vector<vector<T>> values;
    public:
    Matrix(initializer_list<vector<T>> input);
    Matrix(vector<vector<T>> input);
    Matrix<T> operator+(Matrix<T> other);
    Matrix<T> operator-(Matrix<T> other);
    Matrix<T> operator*(T other);
    Matrix<T> operator*(Matrix<T> other);
    MathVector<T> operator*(MathVector<T> other);
    Matrix<T> transpose();
    T get(int row, int column);
    void set(int row, int column, int value);
};

template <typename T>
    Matrix<T>::Matrix(initializer_list<vector<T>> input) {
        values = input;
    }
template <typename T>
    Matrix<T>::Matrix(vector<vector<T>> input) {
        values = input;
    }

template <typename T>
    Matrix<T> Matrix<T>::operator+(Matrix<T> other){
        vector<vector<T>> newValues;
        for(int i = 0; i<values.size();i++){
            vector<T> temp;
            for(int j = 0; j<values[i].size();j++){
                temp.push_back(values[i][j]+other.values[i][j]);
            }
            newValues.push_back(temp);
        }
        return Matrix<T>(newValues);
    }

template <typename T>
    Matrix<T> Matrix<T>::operator-(Matrix<T> other){
        vector<vector<T>> newValues;
        for(int i = 0; i<values.size();i++){
            vector<T> temp;
            for(int j = 0; j<values[i].size();j++){
                temp.push_back(values[i][j]-other.values[i][j]);
            }
            newValues.push_back(temp);
        }
        return Matrix<T>(newValues);
    }

template <typename T>
    Matrix<T> Matrix<T>::operator*(T other){
        vector<vector<T>> newValues;
        for(int i = 0; i<values.size();i++){
            vector<T> temp;
            for(int j = 0; j<values[i].size();j++){
                temp.push_back(values[i][j]*other);
            }
            newValues.push_back(temp);
        }
        return Matrix<T>(newValues);
    }

template <typename T>
    Matrix<T> Matrix<T>::operator*(Matrix<T> other){
        vector<vector<T>> newValues;
        for(int i = 0; i<values.size();i++){
            vector<T> temp;
            for(int j = 0; j<values[i].size();j++){
                T sum = 0;
                for(int k = 0; k<values[i].size();k++){
                    sum += values[i][k]*other.values[k][j];
                }
                temp.push_back(sum);
            }
            newValues.push_back(temp);
        }
        return Matrix<T>(newValues);
    }
    template <typename T>
    MathVector<T> Matrix<T>::operator*(MathVector<T> other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            T sum = 0;
            for(int j = 0; j<values[i].size();j++){
                sum += values[i][j]*other.get(j);
            }
            newValues.push_back(sum);
        }
        return MathVector<T>(newValues);
    }
    template <typename T>
    Matrix<T> Matrix<T>::transpose(){
        vector<vector<T>> newValues;
        for(int i = 0; i<values.size();i++){
            vector<T> temp;
            for(int j = 0; j<values[i].size();j++){
                temp.push_back(values[j][i]);
            }
            newValues.push_back(temp);
        }
        return Matrix<T>(newValues);
    }

    template <typename T>
    T Matrix<T>::get(int row, int col){
        return values[row][col];
    }
    template <typename T>
    void Matrix<T>::set(int row, int col, int value){
        values[row][col] = value;
    }

#endif