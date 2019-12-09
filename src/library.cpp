#include "library.h"

#include <iostream>

void hello()
{
    std::cout << "Hello, World!" << std::endl;
    int i;
    std::cin >> i;
    if (i)
    {
        std::cout << "i = 0";
    }
}
