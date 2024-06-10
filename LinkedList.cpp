#ifndef LL_H
#define LL_H

template <typename T>
class LinkedList
{
private:
    struct NodeType
    {
        T data;
        NodeType* next;
        NodeType() : data(), next(nullptr) 
        {
        }
        NodeType(const T& d) : data(d), next(nullptr) 
        {
        }
    };
    NodeType* head;
    int size;

public:
    LinkedList() : size(0)
    {
        head = new NodeType();
    }

    ~LinkedList()
    {
        clear();
        delete head;
    }

    bool empty() const
    {
        return head->next == nullptr;
    }

    void clear()
    {
        while (!empty())
        {
            pop_front();
        }
    }

    int get_size() const
    {
        int count = 0;
        NodeType* current = head->next;
        while (current!= nullptr)
        {
            count++;
            current = current->next;
        }
        return count;
    }

    bool find(const T& item) const
    {
        NodeType* current = head->next;
        while (current!= nullptr)
        {
            if (current->data == item)
                return true;
            current = current->next;
        }
        return false;
    }

    void push_front(const T& item)
    {
        NodeType* newNode = new NodeType(item);
        newNode->next = head->next;
        head->next = newNode;
    }

    void pop_front()
    {
        if (!empty())
        {
            NodeType* oldNode = head->next;
            head->next = oldNode->next;
            delete oldNode;
        }
    }

public:
    class iterator
    {
    private:
        NodeType* current;

    public:
        iterator() : current(nullptr) {}
        iterator(NodeType* startNode) : current(startNode) {}

        T& operator*()
        {
            return current->data;
        }

        iterator& operator++()
        {
            if (current!= nullptr)
                current = current->next;
            return *this;
        }

        bool operator!=(const iterator& other) const
        {
            return current!= other.current;
        }
    };

    iterator begin() const
    {
        return iterator(head->next);
    }

    iterator end() const
    {
        return iterator(nullptr);
    }
};

#endif // LL_H