#include <iostream>
#include <iomanip>
#include "stack.h"

bool is_palindrome(const std::string word)
{
    Stack<char> s(word.size());

    for (char c : word) {
        s.push(c);
    }

    for (char c : word) {
        if (c != s.pop()) {
            return false;
        }
    }

    return true;
}

int main()
{
    Stack<char> s(5);
    std::cout << std::boolalpha;
    s.push('a');
    s.push('b');
    s.push('c');
    std::cout << s.size() << "\n";
    std::cout << s.capacity() << "\n";
    std::cout << s.pop() << "\n";
    std::cout << s.peek() << "\n";
    std::cout << s.is_empty() << "\n";
    s.clear();
    std::cout << s.is_empty() << "\n";
    std::cout << is_palindrome("kayak") << "\n";
    std::cout << is_palindrome("boat") << "\n";

    return 0;
}

