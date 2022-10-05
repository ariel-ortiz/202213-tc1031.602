#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>

// Complexity: O(N^2)
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

// Complexity: O(N)
void fill_random(std::vector<int>& values, int max_value)
{
    std::srand(0);
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = std::rand() % max_value;
    }
}

// Complexity: O(N)
void fill_incremental(std::vector<int>& values, int max_value)
{
    double section = max_value / static_cast<double>(values.size());
    double current = 0.0;
    for (int i = 0; i < values.size(); ++i) {
        values.at(i) = static_cast<int>(current);
        current += section;
    }
}

// Complexity: O(N)
void print_vector(const std::vector<int>& values)
{
    for (int e : values) {
        std::cout << e << " ";
    }
    std::cout << "\n";
}

int main()
{
    // std::vector<int> v {5, 2, 4, 1, 6, 8, 7, 3};
    std::vector<int> v(20'000);
    fill_random(v, 1'000);
    // fill_incremental(v, 1'000);

    // print_vector(v);
    std::cout << std::is_sorted(v.begin(), v.end()) << "\n";


    auto start = std::chrono::high_resolution_clock::now();
    selectionsort(v);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(
            stop - start);
    double total_time = duration.count() / 1000000.0;


    // print_vector(v);
    std::cout << std::is_sorted(v.begin(), v.end()) << "\n";
    std::cout << "Total time: " << total_time << " seconds \n";
    return 0;
}
