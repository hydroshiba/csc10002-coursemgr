#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>
#include <iostream>
#include <fstream>

template <typename type>
struct Node {
    type value;
    Node* next;
};

template <typename type>
class List {
private:
    Node<type>* head = nullptr;
    Node<type>* tail = nullptr;

public:
    void append(type val) {
        if(head == nullptr) {
            head = new Node<type>{val, nullptr};
            tail = head;
            return;
        }

        tail->next = new Node<type>{val, nullptr};
        tail = tail->next;
    }

    void prepend(type val) {
        if(head == nullptr) {
            append(val);
            return;
        }

        Node<type>* temp = new Node<type>{val, head};
        head = temp;
    }

    void clear() {
        while(head) {
            Node<type>* cur = head;
            head = head->next;
            delete cur;
        }

        tail = nullptr;
    }

    void remove(type val, int amount = -1) {
        Node<type>* cur = head;
        Node<type>* pre = new Node<type>{NULL, head};
        head = pre;

        while(cur){
            if(amount == 0) break;

            if(cur->value != val){
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

    Node<type>* search(type val) {
        Node<type>* cur = head;

        while(cur) {
            if(cur->value == val) return cur;
            cur = cur->next;
        }
        
        return nullptr;
    }

    void display(std::ostream &fout = std::cout) {
        Node<type>* cur = head;
        
        while(cur) {
            fout << cur->value << ' ';
            cur = cur->next;
        }

        fout << std::endl;
    }
};

#endif