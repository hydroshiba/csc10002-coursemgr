#ifndef NODE_H
#define NODE_H

template <typename Type>
struct Node {
	Type value;
	Node* next;

	Node() : next(nullptr) {}
};

#endif