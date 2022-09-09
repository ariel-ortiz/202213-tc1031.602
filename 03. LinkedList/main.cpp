#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList<int> my_list;
    my_list.insert_front(7);
    my_list.insert_front(10);
    my_list.insert_front(3);

    std::cout << my_list.size() << "\n";
    std::cout << my_list.to_string() << "\n";

    std::cout << my_list.remove_front() << "\n";
    std::cout << my_list.size() << "\n";
    std::cout << my_list.to_string() << "\n";

    my_list.insert_back(15);
    my_list.insert_back(16);
    my_list.insert_back(23);

    std::cout << my_list.size() << "\n";
    std::cout << my_list.to_string() << "\n";

    LinkedList<std::string> str_list {"one", "two", "three", "four", "five"};

    std::cout << str_list.size() << "\n";
    std::cout << str_list.to_string() << "\n";

    return 0;
}
