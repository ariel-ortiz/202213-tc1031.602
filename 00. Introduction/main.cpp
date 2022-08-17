#include <iostream>
#include "factorial.h"

int main()
{
    std::cout << "Hello, world!\n";
    int n = 4;
    int x = fact(n);
    std::cout << "The factorial of " << n << " is " << x << "\n";
    return 0;
}

