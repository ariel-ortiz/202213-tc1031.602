#include <iostream>
#include "linkedlist.h"

int main()
{
    LinkedList<int> my_list;
    my_list.insert_front(7);
    my_list.insert_front(10);
    my_list.insert_front(3);

    std::cout << my_list.to_string() << "\n";

    return 0;
}
