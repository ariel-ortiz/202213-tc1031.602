#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<char> set_char {'a', 'b', 'c'};
    set_char.insert('x');
    set_char.insert('a');
    set_char.erase('b');
    std::cout << set_char.size() << "\n";
    std::cout << set_char.count('a') << "\n";
    std::cout << set_char.count('b') << "\n";

    for (char c : set_char) {
        std::cout << c << ' ';
    }
    std::cout << "\n";

    return 0;
}
