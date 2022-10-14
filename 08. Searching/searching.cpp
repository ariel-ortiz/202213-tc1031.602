#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
int sequential_search(const std::vector<T>& values, const T& target)
{
    for (int i = 0; i < values.size(); ++i) {
        if (target == values[i]) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int binary_search(const std::vector<T>& values, const T& target)
{
    int min = 0;
    int max = values.size() - 1;

    while (min <= max) {
        int mid = min + (max - min) / 2; // equivalent to:
                                         // (min + max) / 2
                                         // but without overflowing
        if (target < values[mid]) {
            max = mid - 1;
        } else if (values[mid] < target) {
            min = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main()
{
    std::vector<std::string> v {
        "January", "February", "March",
        "April", "May", "June",
        "July", "August", "September",
        "October", "November", "December"
    };

    std::cout << sequential_search(v, std::string("October")) << "\n";
    std::cout << sequential_search(v, std::string("Funauary")) << "\n";

    std::sort(v.begin(), v.end());

    std::cout << binary_search(v, std::string("October")) << "\n";
    std::cout << binary_search(v, std::string("Funauary")) << "\n";

    return 0;
}

