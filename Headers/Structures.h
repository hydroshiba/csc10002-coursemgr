#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <iostream>
#include <fstream>
#include <cassert>

template <typename Type>
struct Node {
    Type value;
    Node* next;
};

template <typename Type>
struct List {
    Node<Type>* head = nullptr;
    Node<Type>* tail = nullptr;

    List() {}

    List(const List<Type> &list) {
        clear();
        Node<Type>* cur = list.head;
        
        while(cur) {
            append(cur->value);
            cur = cur->next;
        }
    }

    void operator=(const List<Type> &list) {
        clear();
        Node<Type>* cur = list.head;
        
        while(cur) {
            append(cur->value);
            cur = cur->next;
        }
    }

    void append(const Type &value) {
        if(head == nullptr) {
            head = new Node<Type>{value, nullptr};
            tail = head;
            return;
        }

        tail->next = new Node<Type>{value, nullptr};
        tail = tail->next;
    }

    void prepend(const Type &value) {
        if(head == nullptr) {
            append(value);
            return;
        }

        Node<Type>* temp = new Node<Type>{value, head};
        head = temp;
    }

    void clear() {
        while(head) {
            Node<Type>* cur = head;
            head = head->next;
            delete cur;
        }

        tail = nullptr;
    }

    void remove(const Type &value, int amount = -1) {
        Node<Type>* cur = head;
        Node<Type>* pre = new Node<Type>{NULL, head};
        head = pre;

        while(cur){
            if(amount == 0) break;

            if(cur->value != value){
                pre = cur;
                cur = cur->next;
                continue;
            }

            if(cur == tail) tail = pre;

            pre->next = cur->next;
            delete cur;
            cur = pre->next;

            --amount;
        }

        cur = head;
        head = head->next;
        delete cur;
    }

    Node<Type>* find(const Type &value) {
        Node<Type>* cur = head;

        while(cur) {
            if(cur->value == value) return cur;
            cur = cur->next;
        }
        
        return nullptr;
    }

    void display(std::ostream &fout = std::cout) {
        Node<Type>* cur = head;
        
        while(cur) {
            fout << cur->value << ' ';
            cur = cur->next;
        }

        fout << std::endl;
    }

    ~List() {
        clear();
    }
};

template <typename Type, class Compare = std::less<Type>>
struct OrderedList : List<Type> {
private:
    using List<Type>::append;
    using List<Type>::prepend;
    Compare func;

public:
    OrderedList() {}

    OrderedList(const OrderedList<Type> &list) {
        this->clear();
        Node<Type>* cur = list.head;
        
        while(cur) {
            append(cur->value);
            cur = cur->next;
        }
    }

    void operator=(const OrderedList<Type> &list) {
        this->clear();
        Node<Type>* cur = list.head;
        
        while(cur) {
            append(cur->value);
            cur = cur->next;
        }
    }

    void insert(const Type &value) {
        if(this->head == nullptr || !func(this->head->value, value)) {
            prepend(value);
            return;
        }

        Node<Type>* cur = this->head;

        while(cur->next) {
            if(!func(cur->next->value, value)) break;
            cur = cur->next;
        }

        Node<Type>* temp = new Node<Type>{value, cur->next};
        if(cur == this->tail) this->tail = temp;
        cur->next = temp;
    }
};

template <typename Type>
struct Vector {
private:
    size_t length = 0;
    size_t capacity = 1;
    Type* array = nullptr;

    void reallocate(size_t newCapacity) {
        while(capacity < newCapacity) capacity *= 2;
        Type* temp = new Type[capacity]();
            
        for(size_t i = 0; i < length; ++i) 
            temp[i] = array[i];
        
        if(array) delete[] array;
        array = temp;
    }

public:
    Vector() : length{0}, capacity{1}, array{new Type[1]()} {}

    Vector(size_t size) {
        length = size;
        capacity = size;
        array = new Type[size]();
    }

    Vector(const Vector<Type> &vec) {
        resize(vec.size());

        for(int i = 0; i < length; ++i)
            array[i] = vec[i];
    }

    size_t size() const {
        return length;
    }

    Type& operator[](size_t pos) const {
        assert(("Out of bound access!", pos < length));
        return array[pos];
    }

    void operator=(const Vector<Type> &vec) {
        resize(vec.size());
        
        for(int i = 0; i < length; ++i)
            array[i] = vec[i];
    }

    Type* begin() {
        return array;
    }

    Type* end() {
        return array + length + 1;
    }

    void resize(size_t size) {
        if(size > capacity) reallocate(size);
        else if(size > length) {
            Type* init = new Type();

            for(size_t i = length; i < size; ++i)
                array[i] = *init;

            delete init;
        }

        length = size;
    }

    void append(const Type &value) {
        if(length == capacity) reallocate(length + 1);
        array[length] = value;
        ++length;
    }

    void remove(const Type &value, int amount = -1) {
        size_t cur = 0;

        for(size_t i = 0; i < length; ++i) {
            if(amount && array[i] == value) {
                --amount;
                continue;
            }

            array[cur] = array[i];
            array[i].~Type();
            ++cur;
        }

        resize(cur);
    }

    void remove(Type* const ptr) {
        if(ptr - begin() < 0) return;
        if(ptr - begin() >= length) return;

        size_t pos = ptr - begin();
        for(size_t i = pos; i < length - 1; ++i) {
            array[i] = array[i + 1];
        }

        resize(length - 1);
    }

    Type* find(const Type &value) {
        for(size_t i = 0; i < length; ++i) 
            if(value == array[i]) return (array + i);

        return nullptr;
    }

    ~Vector() {
        delete[] array;
    }
};

#endif