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
    vector<T> getValues();
};

template <typename T>
    MathVector<T>::MathVector(initializer_list<T> input) {
        values = input;
    }

    template <typename T>
    MathVector<T>::MathVector(vector<T> input) {
        values = input;
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator+(MathVector<T> other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            newValues.push_back(values[i]+other.values[i]);
        }
        return MathVector<T>(newValues);
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator-(MathVector<T> other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            newValues.push_back(values[i]-other.values[i]);
        }
        return MathVector<T>(newValues);
    }

    template <typename T>
    MathVector<T> MathVector<T>::operator*(T other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            newValues.push_back(values[i]*other);
        }
        return MathVector<T>(newValues);
    }

    template <typename T>
    T MathVector<T>::normalise(){
        T sum = 0;
        for(int i = 0; i<values.size();i++){
            sum += values[i]*values[i];
        }
        T norm = sqrt(sum);
        for(int i = 0; i<values.size();i++){
            values[i] = values[i]/norm;
        }
        return norm;
    }

    template <typename T>
    T MathVector<T>::get(int index){
        return values[index];
    }

    template <typename T>
    vector<T> MathVector<T>::getValues(){
        return values;
    }
#endif