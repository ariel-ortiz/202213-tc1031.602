#include <iostream>
#include <unordered_map>

std::string hex(long n)
{
    if (n == 0) {
        return "0";
    }

    bool is_negative = false;
    if (n < 0) {
        is_negative = true;
        n = -n;
    }

    std::unordered_map<int, std::string> digits = {
        {10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}
    };

    std::string result = "";
    while (n > 0) {
        int rem = n % 16;
        if (rem < 10) {
            result = std::to_string(rem) + result;
        } else {
            result = digits[rem] + result;
        }
        n /= 16;
    }

    return (is_negative ? "-" : "") + result;
}

int main()
{
    std::cout << hex(28) << "\n";
    std::cout << hex(666) << "\n";
    std::cout << hex(3'405'691'582) << "\n";
    std::cout << hex(0) << "\n";
    std::cout << hex(-1023) << "\n";
    return 0;
}
