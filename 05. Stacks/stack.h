#pragma once

#include <stdexcept>

template<typename T>
class Stack {

public:

    Stack(int capacity)
    {
        _data = new T[capacity];
        _top = 0;
        _capacity = capacity;
    }

    ~Stack()
    {
        delete [] _data;
    }

    void push(T value)
    {
        if (_top == _capacity) {
            throw std::overflow_error("Stack overflow error!");
        }
        _data[_top] = value;
        ++_top;
    }

    T pop()
    {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow error!");
        }
        --_top;
        return _data[_top];
    }

    bool is_empty() const
    {
        return _top == 0;
    }

    T peek() const
    {
        if (is_empty()) {
            throw std::underflow_error("Stack underflow error!");
        }
        return _data[_top - 1];
    }

    int size() const
    {
        return _top;
    }

    int capacity() const
    {
        return _capacity;
    }

    void clear()
    {
        _top = 0;
    }

private:

    T* _data;
    int _top;
    int _capacity;
};
