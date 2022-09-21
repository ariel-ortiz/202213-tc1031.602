#include <iostream>
#include <vector>
#include <iomanip>

int main()
{
    std::vector<int> a;
    std::vector<std::string> b {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    a.reserve(10);
    b.reserve(10);

    std::cout << a.size() << " " << a.capacity() << "\n";
    std::cout << b.size() << " " << b.capacity() << "\n";

    b.push_back("a");
    std::cout << b.size() << " " << b.capacity() << "\n";
    b.push_back("b");
    std::cout << b.size() << " " << b.capacity() << "\n";
    b.push_back("c");
    std::cout << b.size() << " " << b.capacity() << "\n";
    b.push_back("d");
    std::cout << b.size() << " " << b.capacity() << "\n";

    for (int i = 0; i < 10; ++i) {
        b.push_back("*");
    }

    std::cout << b.size() << " " << b.capacity() << "\n";

    // b.at(30) = "end"; // Produces a runtime error!

    // for (int i = 0; i < b.size(); ++i) {
    //     std::cout << b.at(i) << "\n";
    // }

    // for (std::vector<std::string>::iterator it = b.begin(); it != b.end(); ++it) {
    //     std::cout << *it << "\n";
    // }

    // for (auto it = b.begin(); it != b.end(); ++it) {
    //     std::cout << *it << "\n";
    // }

    // Reverse iteration
    // for (auto it = b.rbegin(); it != b.rend(); ++it) {
    //     std::cout << *it << "\n";
    // }

    b.insert(b.begin() + 2, "something");
    b.erase(b.begin() + 4);

    std::cout << "\n";

    for (std::string s : b) {
        std::cout << s << "\n";
    }

    // std::cout << b.at(30) << "\n"; // Produces a runtime error!

    std::cout << std::boolalpha;
    std::cout << a.empty() << "\n";
    std::cout << b.empty() << "\n";

    return 0;
}