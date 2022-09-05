#include <iostream>
#include "pystring.h"

int main()
{

    PyString a("--test--test--test--");
    PyString b("--test");
    PyString c("test");
    PyString d("test--");
    PyString e("--");

    std::vector<PyString> return_vector;

    return_vector = a.split("--");

    for (auto i : return_vector)
    {
        std::cout << i << std::endl;
    }

    return_vector = b.split("--");

    for (auto i : return_vector)
    {
        std::cout << i << std::endl;
    }

    return_vector = c.split("--");

    for (auto i : return_vector)
    {
        std::cout << i << std::endl;
    }

    return_vector = d.split("--");

    for (auto i : return_vector)
    {
        std::cout << i << std::endl;
    }

    return_vector = e.split("--");

    for (auto i : return_vector)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
