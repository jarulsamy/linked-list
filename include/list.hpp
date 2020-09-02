#ifndef LIST_HPP
#define LIST_HPP

#include <deque>

template <class T>
class Node
{
public:
    Node(T data) : value(data)
    {
        next = nullptr;
        prev = nullptr;
    }
    Node(T data, Node<T> *pr) : value(data), prev(pr)
    {
        next = nullptr;
    }

    T value;
    Node<T> *next;
    Node<T> *prev;
};

template <class T>
class LinkedList
{
public:
    LinkedList()
    {
        tail = nullptr;
        head = nullptr;
        my_size = 0;
    }
    LinkedList(T data)
    {
        tail = new Node<T>(data);
        head = tail;
        my_size = 1;
    }

    ~LinkedList()
    {
        destroy(tail);
    }

    void push_back(T val)
    {
        if (!tail)
        {
            // Create tail if it doesn't exist
            tail = new Node<T>(val);
            head = tail;
        }
        else
        {
            push_back(val, head->next, head);
        }
    }

    void pop_back()
    {
    }

    size_t size() const
    {
        return my_size;
    }

    void dump(std::deque<T> &container) const
    {
        Node<T> *my_head = tail;

        while (my_head)
        {
            container.push_back(my_head->value);
            my_head = my_head->next;
        }
    }

    void dump_reverse(std::deque<T> &container) const
    {
        Node<T> *my_head = head;

        while (my_head)
        {
            container.push_back(my_head->value);
            my_head = my_head->prev;
        }
    }

private:
    Node<T> *tail;
    Node<T> *head;
    size_t my_size;

    void push_back(T val, Node<T> *&node, Node<T> *&prev_node)
    {
        if (!node)
        {
            node = new Node<T>(val, prev_node);
            head = node;
            ++my_size;
        }
        else
        {
            push_back(val, node->next, node);
        }
    }

    void destroy(Node<T> *&node)
    {
        if (node)
        {
            destroy(node->next);
            delete node;
        }
    }
};

#endif
