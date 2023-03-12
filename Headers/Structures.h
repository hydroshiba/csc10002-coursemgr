#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>
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
protected:
    Node<Type>* head = nullptr;
    Node<Type>* tail = nullptr;

public:
    void append(Type value) {
        if(head == nullptr) {
            head = new Node<Type>{value, nullptr};
            tail = head;
            return;
        }

        tail->next = new Node<Type>{value, nullptr};
        tail = tail->next;
    }

    void prepend(Type value) {
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

    void remove(Type value, int amount = -1) {
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

    Node<Type>* find(Type value) {
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
};

template <typename Type, class Compare = std::less<Type>>
struct OrderedList : List<Type> {
private:
    using List<Type>::append;
    using List<Type>::prepend;

    Compare comp;

public:
    void insert(Type value) {
        if(this->head == nullptr || !comp(this->head->value, value)) {
            prepend(value);
            return;
        }

        Node<Type>* cur = this->head;

        while(cur->next) {
            if(!comp(cur->next->value, value)) break;
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
    size_t length;
    size_t capacity;
    Type* array;

    void reallocate(size_t newCapacity) {
        while(capacity < newCapacity) capacity *= 2;
        Type* temp = new Type[capacity]();
            
        for(size_t i = 0; i < length; ++i) 
            temp[i] = array[i];
        
        delete[] array;
        array = temp;
    }

public:
    Vector() : length{0}, capacity{1}, array{new Type[1]()} {}

    Vector(size_t size) {
        length = size;
        capacity = size;
        array = new Type[size]();
    }

    size_t size() {
        return length;
    }

    Type& operator[](size_t pos) {
        assert(("Out of bound access!", pos < length));
        return array[pos];
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

    void append(Type value) {
        if(length == capacity) reallocate(length + 1);
        array[length] = value;
        ++length;
    }

    void remove(Type value, int amount = -1) {
        size_t cur = 0;

        for(size_t i = 0; i < length; ++i) {
            if(amount == 0) break;
            if(array[i] == value) {
                --amount;
                continue;
            }

            array[cur] = array[i];
            ++cur;
        }

        resize(cur + 1);
    }

    ~Vector() {
        delete[] array;
    }
};

#endif