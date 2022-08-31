#include <iostream>
#include <iomanip>

int main()
{
    int a = 7;
    int* b = &a;
    int** c = &b;
    int*** d = &c;
    int& e = a;

    std::cout << "a = " << a << "\n";
    std::cout << "sizeof(a) = " << sizeof(a) << "\n";
    std::cout << "b = " << b << "\n";
    std::cout << "sizeof(b) = " << sizeof(b) << "\n";
    std::cout << "c = " << c << "\n";
    std::cout << "*b = " << *b << "\n";
    std::cout << "*c = " << *c << "\n";
    std::cout << "**c = " << **c << "\n";
    std::cout << "***d = " << ***d << "\n";

    ++(***d);

    std::cout << "a = " << a << "\n";

    std::cout << "e = " << e << "\n";

    a *= 10;

    std::cout << "e = " << e << "\n";

    e += 20;

    std::cout << "a = " << a << "\n";

    std::cout << std::boolalpha;
    std::cout << "(&a == &e) = " << (&a == &e) << "\n";

    return 0;
}
