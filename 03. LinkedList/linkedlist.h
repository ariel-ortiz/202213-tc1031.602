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
        Node* p = _sentinel->next;
        while (p != _sentinel) {
            if (first_time) {
                first_time = false;
            } else {
                result << ", ";
            }
            result << p->value;
            p = p->next;
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

private:

    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* _sentinel = nullptr;
    int _size = 0;
};
