#include <iostream>

int main()
{
    int x = 42;
    // int* p = nullptr;  // This code produces a segmentation fault
    int* p = &x;          // This one doesn't

    std::cout << *p << "\n";

    return 0;
}