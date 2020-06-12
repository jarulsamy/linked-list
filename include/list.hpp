#pragma once
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

template <class T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node<T> *prev;

    Node()
    {
        next = nullptr;
        prev = nullptr;
    }
    Node(T d)
    {
        Node();
        data = d;
    };
};

template <class T>
class LinkedList
{
public:
    Node<T> *head;
    Node<T> *tail;
    int length;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    ~LinkedList()
    {
        empty();
    }

    void empty() /* Delete all elements */
    {
        if (length > 0)
        {
            Node<T> *my_head = head;
            Node<T> *to_del;
            while (my_head)
            {
                to_del = my_head;
                my_head = my_head->prev;
                delete to_del;
            }
        }
    }

    void insert(T data) /* Add item to list */
    {
        if (!head)
        {
            head = new Node<T>(data);
            tail = head;
        }
        else
        {
            Node<T> *old_head = head;

            head = new Node<T>(data);
            old_head->next = head;
            head->prev = old_head;
        }
        length++;
    }

    bool find(T data) /* Find an item in list */
    {
        Node<T> *my_head = tail;
        while (my_head)
        {
            if (my_head->data == data)
                return true;

            my_head = my_head->next;
        }
        return false;
    }

    void print() /* Print entire list to stdout */
    {
        Node<T> *my_head = tail;

        if (length > 0)
        {
            while (my_head)
            {
                cout << my_head->data << endl;
                my_head = my_head->next;
            }
        }
    }
};

template <>
bool LinkedList<std::string>::find(std::string data)
{
    int data_length = data.length();

    Node<std::string> *my_head = tail;
    while (my_head)
    {
        if (my_head->data.length() == data_length)
        {
            if (!strcmp(my_head->data.c_str(), data.c_str()))
                return true;
        }

        my_head = my_head->next;
    }
    return false;
}
