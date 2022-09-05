#include <iostream>
#include "pystring.h"

int main()
{

    PyString a = "--SPLIT--THIS--TEXT--";

    std::vector<PyString> return_vector;

    a = a.lower();
    a = a.upper();

    return_vector = a.split("--");

    for (auto i : return_vector)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
