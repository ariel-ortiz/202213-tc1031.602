#include <iostream>

int main()
{
    std::hash<std::string> hash_string;
    std::hash<int> hash_int;
    std::hash<float> hash_float;

    std::cout << hash_string("abc") << "\n";
    std::cout << hash_string("ab") << "\n";
    std::cout << hash_int(42) << "\n";
    std::cout << hash_float(42) << "\n";

    std::string x = "abc";
    std::cout << hash_string(x) << "\n";

    return 0;
}
