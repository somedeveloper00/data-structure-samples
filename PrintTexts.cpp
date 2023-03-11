namespace PrintTexts {
    const char* Intro = R"""(

 =====================================================
|                                                     |
|        LIST DATA STRUCTURE SAMPLE & BENCHMARK       |
|                                                     |
|                   by Saeed Barari                   |
|             github.com/somedeveloper00              |
|                                                     |
|                   written in c++                    |
|                                                     |
|      (with help of Bing Chat & Github Copilot)      |
|                                                     |
 -----------------------------------------------------

# Description:
    This is a project to demonstrating the way different data 
    types work, buy showing examples and benchmarks of the given 
    data type. This particular project is aimed only at list 
    types, it includes the following list types:

    * Array:  An array is a collection of items of same data 
               type stored at contiguous memory locations.
    * Linked  List: an ordered set of data elements, each 
               containing a link to its successor.
    * Queue:  a data structure that follows the FIFO (First In 
               First Out) principle, meaning that the first 
               element inserted is the first one to be removed.
    * Stack:  a data structure that follows the LIFO (Last In 
               First Out) principle, meaning that the last element 
               inserted is the first one to be removed.
    
    The project also demonstrates the way sorted lists are used and
    keep them in benchmark.

# Usage:
    --no-intro (-ni):     hides this intro on execution
    --source (-s):        opens a link to source code
    --desc (-d) [LTYPE]:  shows description and c++ code sample for 
                          a list type.
    --benchmark (-b) 
        [LTYPE]:          executes a benchmark on the specified list 
                          type. (only supports array and linked list)

    * Parameters:
        LTYPE:            list type. possible options:
                            'array (arr)', 'linkedlist (ll)', 'queue (q)', 
                            'stack (s)'
)""";


    const char* ArrayDescription = R"""(
An array is a data structure that can store a fixed-size collection of elements of 
the same data type. It allows applying operations to an entire set of values at once. 
An array can be thought of as a collection of variables of the same type. For example, 
an array can store a list of numbers or strings.

Here's a sample c++ class that represents an array collection:

template <typename T> 
class Array {

public:
    int count() { return _count; }

    void add(const int count, const T* items) {
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

    void insert(const int index, const int count, const T* items) {
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
    
    void remove_at(const int index) {
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
    
    void set_at(const int index, T value) {
        _items[index] = value;
    }
    T get_at(const int index) {
        return _items[index];
    }

private:
    T* _items = new T[0];
    int _count = 0;
};
    )""";

    const char* LinkedList = R"""(
A linked list is a data structure that consists of a sequence of nodes, each containing some data and a pointer to the next node. A linked list allows efficient insertion and deletion of elements at any position in the list, without requiring contiguous memory allocation. A linked list can be visualized as a chain of nodes connected by links.

Here's a sample c++ class that represents an linked list collection:


template <typename T> 
class LinkedList {
    
public:
    int count() { 
        int c = 0;
        Node* node = first;
        while(node != nullptr) {
            node = node->next;
            c++;
        }
        return c;
    }

    void add(const int count, const T* items) {
        int c = this->count();
        this->insert(c, count, items);
    }

    void insert(const int index, const int count, const T* items) {
        if (count < 1) return;
        Node* nextNode = nullptr;
        // connect first item to the list
        Node* node = new Node();
        node->data = items[0];
        if (this->count() > 0) {
            if (index == 0) {
                nextNode = this->first->next;
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
    }

    
    void remove_at(const int index) {
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

    void set_at(const int index, T value) {
        _find_node_at(index)->data = value;
    }

    T get_at(const int index) {
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
    )""";

    const char* Queue = R"""(
A queue is a linear data structure that stores elements in a First In First Out (FIFO) order. It means that the element that is added first will be removed first. A queue has two ends: one for adding elements (enqueue) and one for removing elements (dequeue). A queue can be implemented using an array or a linked list.

Here's a sample c++ class that represents an queue using linked list collection:



template <typename T> 
class Queue {
    
public:
    int count() { 
        int c = 0;
        Node* node = first;
        while(node != nullptr) {
            node = node->next;
            c++;
        }
        return c;
    }

    void add(const int count, const T* items) {
        if (count < 1) return;
        int c = this->count();
        // resolve first item
        Node* node = new Node();
        node->data = items[0];
        if (first == nullptr) {
            first = node;
        } else {
            first.next = node;
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

    void insert(const int index, const int count, const T* items) {
        return; // doesn't support insertion
    }
    
    void remove_at(const int index) {
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
    )""";

    const char* Stack = R"""(
A stack is a linear data structure that stores elements in a Last In First Out (LIFO) or First In Last Out (FILO) order. It means that the element that is added last will be removed first. A stack has one end: the top of the stack, where elements are added (push) and removed (pop). A stack can be implemented using an array or a linked list.

Here's a sample c++ class that represents an stack using linked list collection:



template <typename T> 
class Stack {
    
public:
    int count() { 
        int c = 0;
        Node* node = first;
        while(node != nullptr) {
            node = node->next;
            c++;
        }
        return c;
    }

    void add(const int count, const T* items) {
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
    
    void insert(const int index, const int count, const T* items) {
        return; // doesn't support insertion
    }

    
    void remove_at(const int index) {
        return; // doesn't support deletion
    }

    void set_at(const int index, T value) {
        return; // doesn't support set
    }

    T get_at(const int index) {
        return; // doesn't support get
    }


private:
    struct Node {
        T data;
        Node* next = nullptr;
    };

    Node* first = nullptr;
};
    )""";
}