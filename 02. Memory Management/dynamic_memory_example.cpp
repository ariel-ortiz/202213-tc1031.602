#include <iostream>

int main()
{
    int* ptr;
    int* array;

    ptr = new int(42);
    array = new int[10] {1, 2, 3};

    std::cout << *ptr << "\n";
    std::cout << ptr << "\n";
    std::cout << array[0] << "\n";
    std::cout << *array << "\n";
    std::cout << array[2] << "\n";
    std::cout << *(array + 2) << "\n";

    delete ptr;
    delete [] array;

    return 0;
}