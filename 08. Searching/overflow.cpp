#include <iostream>
#include <cstdint>

int main()
{
    int8_t min = 28;
    int8_t max = 100;
    int mid = int8_t(min + max) / 2;
    std::cout << mid << "\n";

    return 0;
}