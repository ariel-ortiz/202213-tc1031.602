#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

void selectionsort(std::vector<int>& values)
{
    for (int i = 0; i < values.size() - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < values.size(); ++j) {
            if (values[j] < values[min_index]) {
                min_index = j;
            }
        }
        std::swap(values[i], values[min_index]);
    }
}

void print_vector(const std::vector<int>& values)
{
    for (int e : values) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> v {5, 2, 4, 1, 6, 8, 7, 3};
    print_vector(v);
    return 0;
}
