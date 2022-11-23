#pragma once

#include <functional>
#include <initializer_list>
#include <queue>

template<typename T>
class TreeSet {

public:

    TreeSet() {}

    // Complexity: O(log N)
    bool add(T value)
    {
        if (_root) {
            Node* p = _root;
            while (true) {
                if (value == p->value) {
                    return false;
                } else if (value < p->value) {
                    if (p->left) {
                        p = p->left;
                    } else {
                        p->left = new Node(value);
                        ++_size;
                        return true;
                    }
                } else {
                    if (p->right) {
                        p = p->right;
                    } else {
                        p->right = new Node(value);
                        ++_size;
                        return true;
                    }
                }
            }
        } else {
            _root = new Node(value);
            ++_size;
            return true;
        }
    }

    void inorder(std::function<void(T)> fn) const
    {
        _inorder(fn, _root);
    }

    void preorder(std::function<void(T)> fn) const
    {
        _preorder(fn, _root);
    }

    void postorder(std::function<void(T)> fn) const
    {
        _postorder(fn, _root);
    }

private:

    struct Node {

        Node(T value)
        {
            this->value = value;
        }

        T value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    void _inorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            _inorder(fn, p->left);
            fn(p->value);
            _inorder(fn, p->right);
        }
    }

    void _preorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            fn(p->value);
            _preorder(fn, p->left);
            _preorder(fn, p->right);
        }
    }

    void _postorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            _postorder(fn, p->left);
            _postorder(fn, p->right);
            fn(p->value);
        }
    }

    Node* _root = nullptr;
    int _size = 0;
};

