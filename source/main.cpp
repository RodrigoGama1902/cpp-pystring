#include <iostream>
#include "pystring.h"
#include <vector>

int main()
{

    PyString a = "_MY_STRING_TEST_";

    std::cout << a << " -> Original String" << std::endl;

    a = a.replace("_", " ");
    std::cout << a << " -> Replace Method" << std::endl;

    a = a.strip();
    std::cout << a << " -> Strip Method" << std::endl;

    a = a.lower();
    std::cout << a << " -> Lower Method" << std::endl;

    a = a.title();
    std::cout << a << " -> Title Method" << std::endl;

    a = a.insert(3, "Python");
    std::cout << a << " -> Insert Method" << std::endl;

    a = a.replace("Python", "Py");
    std::cout << a << " -> Replace Method" << std::endl;

    a = a.remove(11, 16); // TODO Remove method seconds parameter should be "remove until the next index", not the amount of index to remove next
    std::cout << a << " -> Remove Method" << std::endl;

    std::vector<PyString> myvector = a.split(" ");

    for (auto i : myvector)
    {
        std::cout << i << std::endl;
    }

    return 0;
}
