#ifndef MATHVECTOR_H
#define MATHVECTOR_H
#include <vector>
#include <initializer_list>
#include <math.h>


using namespace std;
template <typename T>
class MathVector{
    private:
    vector<T> values;
    public:
    MathVector(initializer_list<T> input);
    MathVector(vector<T> input);
    MathVector<T> operator+(MathVector other);
    MathVector<T> operator-(MathVector other);
    MathVector<T> operator*(T other);
    T normalise();
    T get(int index);
};
#endif