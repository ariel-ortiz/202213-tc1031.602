#include <iostream>
#include "intlist.h"
#include "recursion.h"

int main()
{
    IntList a {4, 8, 15, 16, 23};

    std::cout << first(a) << "\n";
    std::cout << rest(a) << "\n";
    std::cout << first(rest(a)) << "\n";
    std::cout << first(rest(rest(a))) << "\n";
    std::cout << cons(42, a) << "\n";
    std::cout << cons(first(a), rest(rest(a))) << "\n";
    std::cout << is_empty(a) << "\n";
    std::cout << is_empty(rest(rest(rest(rest(rest(a)))))) << "\n";
    std::cout << size(a) << "\n";
    std::cout << cons_end(42, a) << "\n";
    std::cout << sum(a) << "\n";
    std::cout << duplicate(a) << "\n";
    std::cout << last(a) << "\n";
    std::cout << but_last(a) << "\n";
    std::cout << maximum(IntList {5, -1, 10, 2, 8}) << "\n";
    std::cout << append(a, IntList {5, -1, 10, 2, 8}) << "\n";
    std::cout << repeat(10, 1) << "\n";
    std::cout << merge(IntList {1, 2, 3}, IntList {0, 2, 4, 5, 6}) << "\n";

    return 0;
}
