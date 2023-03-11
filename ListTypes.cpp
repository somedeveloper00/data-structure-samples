#include "includes.cpp"
#ifndef LIST_TYPES_CPP
#define LIST_TYPES_CPP

template <typename T> 
class ListType {
public: 
    virtual int count() = 0;
    virtual void add(const int count, const T* items) = 0;
    virtual void add(const T item) = 0;
    virtual void insert(const int index, const int count, const T* items) = 0;
    virtual void remove_at(const int index) = 0;
    virtual void clear() = 0;
    virtual void set_at(const int index, T value) = 0;
    virtual T get_at(const int index) = 0;
    void print(const std::function<std::string(T)> func, const bool space = true) {
        int c = this->count();
        std::cout << "[";
        for (size_t i = 0; i < c; i++) {
            auto str = func(this->get_at(i));
            std::cout << str << ((i == c - 1) ? "" : (space ? ", " : ","));
        }
        std::cout << "]" << std::endl;
    }
};


template <typename T> 
class Array : public ListType<T> {

public:
    int count() override { return _count; }

    void add(const T item) override {
        T* temp = new T[_count+1];
        for (size_t i = 0; i < _count; i++) {
            temp[i] = _items[i];
        }
        temp[_count] = item;
        delete _items;
        _items = temp;
    }
    void add(const int count, const T* items) override {
        auto temp = new T[_count + count];
        for (size_t i = 0; i < _count; i++) {
            temp[i] = _items[i];
        }
        for (size_t i = _count; i < _count + count; i++) {
            temp[i] = items[i - _count];
        }
        _count += count;
        delete[] _items;
        _items = temp;
    }

    void insert(const int index, const int count, const T* items) override {
        auto temp = new T[_count + count];
        for (size_t i = 0; i < index; i++) {
            temp[i] = _items[i];
        }
        for (size_t i = index; i < index + count; i++) {
            temp[i] = items[i-index];
        }
        for (size_t i = index+count; i < _count+count; i++) {
            temp[i] = _items[i - count];
        }
        _count += count;
        delete _items;
        _items = temp;
    }
    
    void clear() override {
        delete _items;
        _items = new T[0];
        _count = 0;
    }

    void remove_at(const int index) override {
        auto temp = new int[_count - 1];
        for (size_t i = 0; i < index; i++) {
            temp[i] = _items[i];
        }
        for (size_t i = index; i < _count - 1; i++) {
            temp[i] = _items[i + 1];
        }
        _count--;
        delete[] _items;
        _items = temp;
    }
    
    void set_at(const int index, T value) override {
        _items[index] = value;
    }
    T get_at(const int index) override {
        return _items[index];
    }

private:
    T* _items = new T[0];
    int _count = 0;
};


template <typename T> 
class LinkedList : public ListType<T> {
    
public:
    int count() override { 
        int c = 0;
        Node* node = first;
        while(node != nullptr) {
            node = node->next;
            c++;
        }
        return c;
    }

    void add(const T item) override {
        Node* node = new Node();
        node->data = item;
        if (first == nullptr) first = node;
        else {
            // find last
            last->next = node;
        }
        last = node;
    }

    void add(const int count, const T* items) override {
        int c = this->count();
        this->insert(c, count, items);
    }

    void insert(const int index, const int count, const T* items) override {
        if (count < 1) return;
        int c = this->count();
        Node* nextNode = nullptr;
        // connect first item to the list
        Node* node = new Node();
        node->data = items[0];
        if (c > 0) {
            if (index == 0) {
                nextNode = this->first;
                this->first = node;
            } else {
                Node* indexnode = this->_find_node_at(index-1);
                nextNode = indexnode->next;
                indexnode->next = node;
            }
        } else {
            this->first = node;
        }

        // create list 
        for (size_t i = 1; i < count; i++) {
            Node* newnode = new Node();
            newnode->data = items[i];
            node->next = newnode;
            node = newnode;
        }
        
        // connect the last node's next to (index+1)'th element
        if (nextNode != nullptr) {
            node->next = nextNode;
        }
        
        if (index == c) last = node;
    }

    void clear() override {
        Node* node = first;
        do {
            auto next = node->next;
            delete node;
            node = next;
        }
        while(node != nullptr);
        first = nullptr;
    }

    void remove_at(const int index) override {
        if (index == 0) {
            Node* node = first->next;
            delete first;
            first = node;
        } else {
            Node* node = this->_find_node_at(index - 1);
            Node* next = node->next;
            node->next = node->next->next;
            delete next;
        }
    }

    void set_at(const int index, T value) override {
        _find_node_at(index)->data = value;
    }

    T get_at(const int index) override {
        return _find_node_at(index)->data;
    }

private:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* first = nullptr;
    Node* last = nullptr;

    void _update_last_node() {
        last = first;
        while(last->next != nullptr) {
            last = last->next;
        }
    }
    Node* _find_node_at(int index) {
        Node* elem = first;
        while(index-- > 0) elem = elem->next;
        return elem;
    }
};


template <typename T> 
class Queue : public ListType<T> {
    
public:
    int count() override { 
        int c = 0;
        Node* node = first;
        while(node != nullptr) {
            node = node->next;
            c++;
        }
        return c;
    }

    void add(const T item) override {
        Node* node = new Node();
        node->data = item;
        // get last
        if (first == nullptr) {
            first = node;
        } else {
            Node* last = first;
            while(last->next != nullptr) last = last->next;
            last->next = node;
        }
    }

    void add(const int count, const T* items) override {
        if (count < 1) return;
        // resolve first item
        Node* node = new Node();
        node->data = items[0];
        if (first == nullptr) {
            first = node;
        } else {
            // get last
            Node* last = first;
            while(last->next != nullptr) last = last->next;
            last->next = node;
        }
        // add rest
        for (size_t i = 1; i < count; i++) {
            Node* newnode = new Node();
            newnode->data = items[i];
            node->next = newnode;
            node = newnode;
        }
    }

    T pop() {
        Node* result = first;
        first = first->next;
        return result->data;
    }

    void insert(const int index, const int count, const T* items) override {
        return; // doesn't support insertion
    }

    void clear() override {
        Node* node = first;
        do {
            auto next = node->next;
            delete node;
            node = next;
        }
        while(node != nullptr);
        first = nullptr;
    }
    
    void remove_at(const int index) override {
        return; // doesn't support deletion
    }

    void set_at(const int index, T value) override {
        _find_node_at(index)->data = value;
    }

    T get_at(const int index) override {
        return _find_node_at(index)->data;
    }


private:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* first = nullptr;
    Node* _find_node_at(int index) {
        Node* elem = first;
        while(index-- > 0) elem = elem->next;
        return elem;
    }
};


template <typename T> 
class Stack : public ListType<T> {
    
public:
    int count() override { 
        int c = 0;
        Node* node = first;
        while(node != nullptr) {
            node = node->next;
            c++;
        }
        return c;
    }


    void add(const T item) override {
        Node* node = new Node();
        node->data = item;
        if (first != nullptr) {
            node->next = first;
        }
        first = node;
    }

    void add(const int count, const T* items) override {
        if (count < 1) return;
        for (size_t i = 0; i < count; i++) {
            Node* node = new Node();
            node->data = items[i];
            node->next = first;
            first = node;
        }
    }

    T pop() {
        Node* result = first;
        first = first->next;
        return result->data;
    }
    
    void insert(const int index, const int count, const T* items) override {
        return; // doesn't support insertion
    }

    void clear() override {
        Node* node = first;
        do {
            auto next = node->next;
            delete node;
            node = next;
        }
        while(node != nullptr);
        first = nullptr;
    }

    void remove_at(const int index) override {
        return; // doesn't support deletion
    }

    void set_at(const int index, T value) override {
        _find_node_at(index)->data = value;
    }

    T get_at(const int index) override {
        return _find_node_at(index)->data;
    }


private:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* first = nullptr;

    Node* _find_node_at(int index) {
        Node* elem = first;
        while(index-- > 0) elem = elem->next;
        return elem;
    }
};


template <typename T> 
class CppVector : public ListType<T> {
    
public:
    int count() override { 
        return _vec.size();
    }

    void add(const T item) override {
        _vec.push_back(item);
    }

    void add(const int count, const T* items) override {
        for (size_t i = 0; i < count; i++) {
            add(items[i]);
        }
    }

    void insert(const int index, const int count, const T* items) override {
        _vec.insert(_vec.begin() + index, items, items + count);
    }

    void clear() override {
        _vec.clear();
    }

    void remove_at(const int index) override {
        _vec.erase(_vec.begin() + index);
    }

    void set_at(const int index, T value) override {
        _vec[index] = value;
    }

    T get_at(const int index) override {
        return _vec[index];
    }

private:
    std::vector<T> _vec;
};


#endif