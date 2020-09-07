#ifndef LIST_HPP
#define LIST_HPP

#include <deque>

/**
 * @brief A member of a linked list.
 *
 * @tparam T Some data to hold.
 */
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

/**
 * @brief A doubly linked list
 *
 * @tparam T Optional first value to set as tail
 * If not set, a tail is created with the first push_back.
 */
template <class T>
class LinkedList
{
public:
    /**
    * @brief Construct a new Linked List object
    *
    */
    LinkedList()
    {
        tail = nullptr;
        head = nullptr;
        my_size = 0;
    }
    /**
     * @brief Construct a new Linked List object
     *
     * @param data Optionally first value to set as tail
     * If not set, a tail is created with the first push_back.
     */
    LinkedList(T data)
    {
        tail = new Node<T>(data);
        head = tail;
        my_size = 1;
    }

    /**
     * @brief Destroy the Linked List object
     *
     */
    ~LinkedList()
    {
        destroy(tail);
    }

    /**
     * @brief Add a value to the end of the list.
     *
     * @param val
     */
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

    /**
     * @brief Remove an element from the list
     *
     */
    void pop_back()
    {
        if (head)
        {
            Node<T> to_del = head;
            head = head->prev;
            head->next = nullptr;
            delete to_del;
        }
    }

    /**
     * @brief Get the total number of elements in the list
     *
     * @return size_t
     */
    size_t size() const
    {
        return my_size;
    }

    /**
     * @brief Dump the list into a deque
     *
     * @param container
     */
    void dump(std::deque<T> &container) const
    {
        Node<T> *my_head = tail;

        while (my_head)
        {
            container.push_back(my_head->value);
            my_head = my_head->next;
        }
    }

    /**
     * @brief Dump the the list in reverse order into a deque
     *
     * @param container
     */
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

    /**
     * @brief Recursively add a node to list
     *
     * @short This is recursive, to ensure the element is always added to end
     * and that the head and tail are on opposing ends.
     *
     * @param val Data to add
     * @param node Current node to add to
     * @param prev_node Prev node to connect to
     */
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

    /**
     * @brief Destroy a node and all subsequent nodes.
     *
     * @param node
     */
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
