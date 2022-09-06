#include <iostream>
#include "pystring.h"

int main()
{

    PyString a = "test another ";
    PyString b = a.insert(0, "teste");

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
