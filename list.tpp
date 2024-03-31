#ifndef LIST_TPP
#define LIST_TPP

#include "list.hpp"

template <typename T>
typename List<T>::size_type List<T>::_size = 0;

template <typename T>
List<T>::List()
    : _head {nullptr}
    , _tail {nullptr} {}

template <typename T>
List<T>::~List()
{
    Node* curr = _head;
    while (_size != 0)
    {
        --_size;
        Node* tmp = curr;
        curr = curr->_next;
        delete tmp;
    }
}

template <typename T>
typename List<T>::pointer List<T>::begin()
{
    return _head;
}

template <typename T>
typename List<T>::pointer List<T>::end()
{
    return _tail->_next;
}

template <typename T>
typename List<T>::const_pointer List<T>::cbegin() const
{
    return _head;
}

template <typename T>
typename List<T>::const_pointer List<T>::cend() const
{
    return _tail->_next;
}

template <typename T>
typename List<T>::reference List<T>::front()
{
    return *_head;
}

template <typename T>
typename List<T>::reference List<T>::back()
{
    return *_tail;
}

template <typename T>
bool List<T>::empty() const
{
    return static_cast<bool>(_size);
}

template <typename T>
void List<T>::clear()
{
    Node* curr = _head;
    while (_size != 0)
    {
        --_size;
        Node* tmp = curr;
        curr = curr->_next;
        delete tmp;
    }
    _head = nullptr;
    _tail = nullptr;
}

template <typename T>
void List<T>::push_front(List::const_reference data)
{
    Node* newNode = new Node(data);

    if (_size == 0)
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        _head->_prev = newNode;
        newNode->_next = _head;
        _head = newNode;
    }

    ++_size;
}

template <typename T>
void List<T>::pop_front()
{
    if (_size == 0)
    {
        throw std::out_of_range("The list is empty");
    }

    if (_size == 1)
    {
        delete _head;
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        _head = _head->_next;
        delete _head->_prev;
        _head->_prev = nullptr;
    }

    --_size;
}

template <typename T>
void List<T>::push_back(List::const_reference data)
{
    Node* newNode = new Node(data);

    if (_size == 0)
    {
        _head = newNode;
        _tail = newNode;
    }
    else
    {
        _tail->_next = newNode;
        newNode->_prev = _tail;
        _tail = newNode;
    }

    ++_size;
}

template <typename T>
void List<T>::pop_back()
{
    if (_size == 0)
    {
        throw std::out_of_range("The list is empty.");
    }

    if (_size == 1)
    {
        delete _tail;
        _head = nullptr;
        _tail = nullptr;
    }
    else
    {
        _tail = _tail->_prev;
        delete _tail->_next;
        _tail->_next = nullptr;
    }

    --_size;
}

template <typename T>
void List<T>::insert(List::size_type pos, List::const_reference data)
{
    if (pos < 0 || pos >= _size)
    {
        throw std::out_of_range("Invalid position.");
    }

    if (_size == 0)
    {
        push_front(data);
    }
    else if (_size == pos)
    {
        push_back(data);
    }
    else
    {
        Node* newNode = new Node(data);
        Node* curr = _head;

        for (size_t i = 0; i < pos - 1; ++i)
        {
            curr = curr->_next;
        }

        curr->_next->_prev = newNode;
        newNode->_next = curr->_next;
        newNode->_prev = curr;
        curr->_next = newNode;

        ++_size;
    }
}

template <typename T>
void List<T>::insert(List<T>::size_type pos, std::initializer_list<T>& ilist)
{

}

template <typename T>
void List<T>::remove(List::size_type pos)
{
    if (pos < 0 || pos >= _size)
    {
        throw std::out_of_range("Invalid position.");
    }

    if (pos == 0)
    {
        pop_front();
    }
    else if (pos == _size - 1)
    {
        pop_back();
    }
    else
    {
        Node* curr = _head;
        for (size_t i = 0; i < pos - 1; ++i)
        {
            curr = curr->_next;
        }
        curr->_next = curr->_next->_next;
        delete curr->_next->_prev;
        curr->_next->_prev = curr;

        --_size;
    }
}

template <typename T>
void List<T>::reverse()
{
    Node* current = _head;
    Node* next = nullptr;
    Node* prev = nullptr;

    while (current != nullptr) {
        next = current->_next;
        current->_next = prev;
        current->_prev = next;
        prev = current;
        current = next;
    }

    Node* temp = _head;
    _head = _tail;
    _tail = temp;
}


template <typename T>
void List<T>::print() const
{
    Node* curr = _head;
    while (curr != nullptr)
    {
        std::cout << curr->_data << " ";
        curr = curr->_next;
    }
    std::cout << std::endl;
}

template <typename T>
void List<T>::rprint() const
{
    Node* curr = _tail;
    while (curr != nullptr)
    {
        std::cout << curr->_data << " ";
        curr = curr->_prev;
    }
    std::cout << std::endl;
}

template <typename T>
typename List<T>::Node* List<T>::getMiddleNode() const
{
    Node* hare = _head->_next;
    Node* tortoise = _head;

    while (hare->_next != nullptr && hare != nullptr)
    {
        hare = hare->_next->_next;
        tortoise = tortoise->_next;
    }

    return tortoise;
}

template <typename T>
bool List<T>::hasCycle() const
{
    Node* hare = _head->_next;
    Node* tortoise = _head;

    while (hare->_next != nullptr && hare != nullptr)
    {
        hare = hare->_next->_next;
        tortoise = tortoise->_next;

        if (hare == tortoise)
        {
            return true;
        }
    }

    return false;
}

template <typename T>
typename List<T>::size_type List<T>::getStartPoint() const
{
    Node* hare = _head;
    Node* tortoise = _head;

    while (hare != nullptr && hare->_next != nullptr)
    {
        hare = hare->_next->_next;
        tortoise = tortoise->_next;

        if (hare == tortoise)
        {
            tortoise = _head;
            size_t index = 0;

//            std::cout << "aaa" <<tortoise->_data << std::endl;
//            std::cout << "aaa"<< hare->_data << std::endl;

            while (hare != tortoise)
            {
                ++index;
                hare = hare->_next;
                tortoise = tortoise->_next;
            }

            return index;
        }
    }

    return 0;
}


template <typename T>
List<T>::Node::Node()
    : _next {nullptr}
    , _prev {nullptr}
    , _data {value_type()} {}

template <typename T>
List<T>::Node::Node(List::const_reference data)
    : _next {nullptr}
    , _prev {nullptr}
    , _data {data} {}

#endif // LIST_TPP