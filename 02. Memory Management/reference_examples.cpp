#include <iostream>

void swap_v1(int x, int y) // pass by value
{
    int t = x;
    x = y;
    y = t;
}

void swap_v2(int& x, int& y) // pass by reference
{
    int t = x;
    x = y;
    y = t;
}

int main()
{
    int a = 5;
    int b = 8;

    std::cout << "a = " << a << ", b = " << b << "\n";
    swap_v1(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n";
    swap_v2(a, b);
    std::cout << "a = " << a << ", b = " << b << "\n";

    return 0;
}