#include <iostream>
#include "pystring.h"
#include <vector>

int main()
{

    PyString a = "aloutestealoutestealouteste";
    // PyString b = a.replace("alou", "_");

    std::vector<PyString> myvector = a.split("teste");

    for (auto i : myvector)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
