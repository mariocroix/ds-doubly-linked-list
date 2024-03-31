#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class List
{
private:
    struct Node;
public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;
    using size_type = size_t;

    List();
    ~List();
    pointer begin();
    pointer end();
    const_pointer cbegin() const;
    const_pointer cend() const;
    reference front();
    reference back();
    bool empty() const;
    void clear();
    void push_front(const_reference);
    void pop_front();
    void push_back(const_reference);
    void pop_back();
    void insert(size_type, const_reference);
    void insert(size_type, std::initializer_list<value_type>&);
    void remove(size_type);
    void reverse();
    void print() const;
    void rprint() const;
    Node* getMiddleNode() const;
    bool hasCycle() const;
    size_type getStartPoint() const;

private:
    struct Node
    {
        Node* _next;
        Node* _prev;
        value_type _data;
        Node();
        explicit Node(const_reference);
    };

    Node* _head;
    Node* _tail;
    static size_type _size;
};

#include "list.tpp"

#endif // LIST_HPP