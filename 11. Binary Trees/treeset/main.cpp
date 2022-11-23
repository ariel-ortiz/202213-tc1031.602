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

    return 0;
}
