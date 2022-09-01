#include <iostream>

int main()
{
    int x = 42;
    // int* p = nullptr;  // This code produces a segmentation fault
    int* p = &x;          // This one doesn't
    int a[10] {4, 5, 6};

    std::cout << *p << "\n";
    // std::cout << a[1000] << "\n";  // Illegal memory access.

    return 0;
}