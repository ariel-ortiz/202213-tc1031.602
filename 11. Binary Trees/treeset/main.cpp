#include <iostream>
#include <vector>
#include "treeset.h"

void print_value(int x)
{
    std::cout << x << " ";
}

int main()
{
    TreeSet<int> a {15, 8, 20, 23, 21, 3, 1, 9};

    a.inorder(print_value);
    std::cout << "\n";

    a.preorder(print_value);
    std::cout << "\n";

    a.postorder(print_value);
    std::cout << "\n";

    a.inorder([&] (int x) { std::cout << x << "\n"; });
    std::cout << "\n";

    int sum = 0;
    a.preorder([&] (int x) { sum += x; });
    std::cout << "sum = " << sum << "\n";

    int even = 0;
    a.postorder([&] (int x) {
        if (x % 2 == 0) {
            ++even;
        }
    });
    std::cout << "even = " << even << "\n";

    TreeSet<char> b {'h', 'e', 'l', 'l', 'o', 'w', 'o', 'r', 'l', 'd'};
    b.levelorder([&] (char c) { std::cout << c << " "; });
    std::cout << "\n";
    std::cout << b.height() << "\n";
    std::cout << b.is_full() << "\n";

    return 0;
}
