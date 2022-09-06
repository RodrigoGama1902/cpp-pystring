#include <iostream>
#include "pystring.h"

int main()
{

    PyString a = "test   ";

    a = a.capitalize();
    std::cout << a << std::endl;

    return 0;
}
