#pragma once

#include <sstream>
#include <stdexcept>

template<typename T>
class LinkedList {

public:

    // Forbid copy construction (initialization)
    LinkedList(const LinkedList& other) = delete;

    // Forbid assignment
    LinkedList<T>& operator=(const LinkedList& other) = delete;

    // Complexity: O(1)
    // Default constructor
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->next = _sentinel;
        _sentinel->prev = _sentinel;
    }

    // Complexity: O(N)
    LinkedList(std::initializer_list<T> args): LinkedList()
    {
        for (T arg: args) {
            insert_back(arg);
        }
    }

    // Complexity: O(N)
    ~LinkedList()
    {
        Node* current = _sentinel->next;

        while (current != _sentinel) {
            Node* p = current;
            current = current->next;
            delete p;
        }
        delete _sentinel;
    }

    // Complexity: O(1)
    void insert_front(T value)
    {
        Node* new_node = new Node;
        new_node->value = value;

        new_node->next = _sentinel->next;
        new_node->prev = _sentinel;
        _sentinel->next->prev = new_node;
        _sentinel->next = new_node;

        ++_size;
    }

    // Complexity: O(1)
    void insert_back(T value)
    {
        Node* new_node = new Node;
        new_node->value = value;

        new_node->prev = _sentinel->prev;
        new_node->next = _sentinel;
        _sentinel->prev->next = new_node;
        _sentinel->prev = new_node;

        ++_size;
    }

    // Complexity: O(1)
    int size() const
    {
        return _size;
    }

    // Complexity: O(N)
    std::string to_string() const
    {
        std::ostringstream result;
        result << "[";
        bool first_time = true;
        for (T value : *this) {
            if (first_time) {
                first_time = false;
            } else {
                result << ", ";
            }
            result << value;
        }
        result << "]";
        return result.str();
    }

    // Complexity: O(1)
    bool is_empty() const
    {
        return not size();
    }

    // Complexity: O(1)
    T remove_front()
    {
        if (is_empty()) {
            throw std::length_error(
                "Can't remove from the front of an empty list");
        }

        T value = _sentinel->next->value;
        Node* p = _sentinel->next;
        _sentinel->next = p->next;
        p->next->prev = _sentinel;
        delete p;
        --_size;
        return value;
    }

    // Complexity: O(N), where N is the size of other
    void extend(const LinkedList<T>& other)
    {
        for (T value : other) {
            insert_back(value);
        }
    }

private:

    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    class LinkedListIterator {

    public:

        // Complexity: O(1)
        // Constructor
        LinkedListIterator(Node* current)
        {
            _current = current;
        }

        // Complexity: O(1)
        // Dereference operator
        T operator*() const
        {
            return _current->value;
        }

        // Complexity: O(1)
        // Pre-increment operator
        void operator++()
        {
            _current = _current->next;
        }

        // Complexity: O(1)
        // Inequality operator
        bool operator!=(const LinkedListIterator& other) const
        {
            return _current != other._current;
        }

    private:

        Node* _current;
    };

    Node* _sentinel = nullptr;
    int _size = 0;

public:

    // Complexity: O(1)
    // “Pointer” to the start of the collection
    LinkedListIterator begin() const
    {
        return LinkedListIterator(_sentinel->next);
    }

    // Complexity: O(1)
    // “Pointer” to the end of the collection
    LinkedListIterator end() const
    {
        return LinkedListIterator(_sentinel);
    }
};

// Complexity: O(N)
template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
{
    return os << list.to_string();
}
