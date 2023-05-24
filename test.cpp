#include "test.h"
#include <iostream>

Test::Test()
{
    std::cout << "Test constructor" << std::endl;
}

void Test::print()
{
    std::cout << "Test print" << std::endl;
}
