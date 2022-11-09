#include <iostream>

long fact(int n)
{
    if (n <= 0) {
        return 1;
    } else {
        return n * fact(n + 1);
    }
}

int main()
{
    std::cout << "4! = " << fact(4) << "\n";
    std::cout << "10! = " << fact(10) << "\n";
    std::cout << "20! = " << fact(20) << "\n";
    std::cout << "21! = " << fact(21) << "\n";
    return 0;
}
