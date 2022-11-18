#include "intlist.h"
#include "recursion.h"

// Complexity: O(N)
int size(const IntList& a)
{
    if (is_empty(a)) {
        return 0;
    } else {
        return 1 + size(rest(a));
    }
}

// Complexity: O(N)
IntList cons_end(int value, const IntList& a)
{
    if (is_empty(a)) {
        return IntList {value};
    } else {
        return cons(first(a), cons_end(value, rest(a)));
    }
}

// Complexity: O(N)
int sum(const IntList& a)
{
    if (is_empty(a)) {
        return 0;
    } else {
        return first(a) + sum(rest(a));
    }
}

// Complexity: O(N)
IntList duplicate(const IntList& a)
{
    if (is_empty(a)) {
        return IntList {};
    } else {
        return cons(first(a), cons(first(a), duplicate(rest(a))));
    }
}

// Complexity: O(N)
int last(const IntList& a)
{
    if (is_empty(rest(a))) {
        return first(a);
    } else {
        return last(rest(a));
    }
}

// Complexity: O(N)
IntList but_last(const IntList& a)
{
    if (is_empty(rest(a))) {
        return IntList {};
    } else {
        return cons(first(a), but_last(rest(a)));
    }
}

// Complexity: O(N)
int maximum(const IntList& a)
{
    if (is_empty(rest(a))) {
        return first(a);
    } else {
        return std::max(first(a), maximum(rest(a)));
    }
}

// Complexity: O(N), where N is the size of a
IntList append(const IntList& a, const IntList& b)
{
    if (is_empty(a)) {
        return b;
    } else {
        return cons(first(a), append(rest(a), b));
    }
}

// Complexity: O(N)
IntList repeat(int n, int value)
{
    if (n == 0) {
        return IntList {};
    } else {
        return cons(value, repeat(n - 1, value));
    }
}

IntList reverse(const IntList& a)
{
    return IntList {};
}


// Complexity: O(N), where N is the sum of the sizes of both lists a and b
//             O(N + M), where N is the size of a, and M is the size of b
IntList merge(const IntList& a, const IntList& b)
{
    if (is_empty(a)) {
        return b;
    } else if (is_empty(b)) {
        return a;
    } else if (first(a) < first(b)) {
        return cons(first(a), merge(rest(a), b));
    } else {
        return cons(first(b), merge(a, rest(b)));
    }
}

bool is_prefix(const IntList& a, const IntList& b)
{
    return false;
}

// Complexity: O(N)
IntList insert(int value, const IntList& a)
{
    if (is_empty(a)) {
        return IntList {value};
    } else if (value <= first(a)) {
        return cons(value, a);
    } else {
        return cons(first(a), insert(value, rest(a)));
    }
}

IntList insertion_sort(const IntList& a)
{
    return IntList {};
}

// Complexity: O(N log N)
IntList binary(int n)
{
    if (n == 0) {
        return IntList {};
    } else {
        return cons_end(n % 2, binary(n / 2));
    }
}
