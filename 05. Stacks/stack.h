#pragma once

#include <stdexcept>

template<typename T>
class Stack {

public:

    // Complexity: O(1)
    Stack(int capacity)
    {
        _data = new T[capacity];
        _top = 0;
        _capacity = capacity;
    }

    // Delete copy constructor
    Stack(const Stack& other) = delete;

    // Delete assignment operator
    Stack<T>& operator=(const Stack& other) = delete;

    // Complexity: O(1)
    ~Stack()
    {
        delete [] _data;
    }

    // Complexity: O(1)
    void push(T value)
    {
        if (_top == _capacity) {
            throw std::overflow_error("Stack overflow error!");
        }
        _data[_top] = value;
        ++_top;
    }

    // Complexity: O(1)
    T pop()
    {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow error!");
        }
        --_top;
        return _data[_top];
    }

    // Complexity: O(1)
    bool is_empty() const
    {
        return _top == 0;
    }

    // Complexity: O(1)
    T peek() const
    {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow error!");
        }
        return _data[_top - 1];
    }

    // Complexity: O(1)
    int size() const
    {
        return _top;
    }

    // Complexity: O(1)
    int capacity() const
    {
        return _capacity;
    }

    // Complexity: O(1)
    void clear()
    {
        _top = 0;
    }

private:

    T* _data;
    int _top;
    int _capacity;
};
