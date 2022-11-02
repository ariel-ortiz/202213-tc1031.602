#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<int, std::string> my_map;
    my_map[0] = "zero";
    my_map[5] = "five";
    my_map[10] = "ten";
    my_map[11] = "eleven";

    std::cout << my_map.size() << "\n";
    std::cout << my_map.count(5) << "\n";
    std::cout << my_map.count(6) << "\n";
    std::cout << my_map[10] << "\n";
    std::cout << my_map[20] << "\n";

    my_map.erase(20);

    for (auto p : my_map) {
        std::cout << p.first << ": " << p.second << "\n";
    }

    return 0;
}