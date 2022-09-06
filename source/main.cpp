#include <iostream>
#include "pystring.h"

int main()
{

    PyString a = "teste testea";
    PyString b = a.replace("teste", "this");

    // std::cout << a << std::endl;
    std::cout << b << std::endl;

    return 0;
}
