#include "mathVector.h"

using namespace std;

class MathVector{
    MathVector::MathVector(initializer_list<T> input) {
        values = input;
    }
    MathVector::MathVector(vector<T> input) {
        values = input;
    }
    MathVector<T> MathVector::operator+(MathVector<T> other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            newValues.push_back(values[i]+other.values[i]);
        }
        return MathVector<T>(newValues);
    }
    MathVector<T> MathVector::operator-(MathVector<T> other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            newValues.push_back(values[i]-other.values[i]);
        }
        return MathVector<T>(newValues);
    }
    MathVector<T> MathVector::operator*(T other){
        vector<T> newValues;
        for(int i = 0; i<values.size();i++){
            newValues.push_back(values[i]*other);
        }
        return MathVector<T>(newValues);
    }
    T MathVector::normalise(){
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
    T MathVector::get(int index){
        return values[index];
    }
}