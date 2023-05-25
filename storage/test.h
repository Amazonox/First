#ifndef TEST_H
#define TEST_H
#include <iostream>

using namespace std; 
template <class T>
class Test
{
private:
    T value;
public:
    Test(T value);
    void print();
};

template <class T>
Test<T>::Test(T value)
{
    std::cout << "Test constructor" << std::endl;
    this->value = value;
}

template <class T>
void Test<T>::print()
{
    std::cout << "print t" << std::endl;
}
#endif 
