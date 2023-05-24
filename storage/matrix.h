#define MATRIX_H
#include <vector>
#include <initializer_list>
#include <math.h>
#include "MathVector.h"

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