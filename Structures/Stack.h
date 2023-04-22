#ifndef STACK_H
#define STACK_H

#include <cassert>
#include "Node.h"

template <typename Type>
class Stack {
private:
	Node<Type>* head;

public:
	Stack() : head(nullptr) {}

	bool empty() {
		return (head == nullptr);
	}

	void push(const Type &value) {
		Node<Type>* cur = new Node<Type>;
		cur->value = value;
		cur->next = head;

		head = cur;
	}

	void pop() {
		assert(("Stack is empty!", !empty()));

		Node<Type>* cur = head;
		head = head->next;
		delete cur;
	}

	Type top() {
		assert(("Stack is empty!", !empty()));
		return head->value;
	}

	~Stack() {
		Node<Type>* cur = head;
		
		while(cur) {
			head = head->next;
			delete cur;
			cur = head;
		}
	}
};

#endif