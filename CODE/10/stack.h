#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename type>			
class Node {
public:
	type data;
	Node<type>* next;
};

template <typename type>
class Stack {

public:
  // Constructor
  explicit Stack();

  // Destructor
  ~Stack();

  // Store new element
  void push(const type& item);

  // Return first element
  type& top() const;

  // Remove first element
  void pop();

  // Return true if empty, false otherwise
  bool empty() const;

  // Number of elements stored
  int size() const;
  
private: 
	Node<type>* head;
	int n;
};

// Implement functions below

template <typename type>
Stack<type>::Stack() 
	: head(NULL), n(0) {} 				


template <typename type>
Stack<type>::~Stack() {
	Node<type>* current;
	while (head != NULL){
		current = head;
		head = current->next;
		delete current;
	}
	n = 0;
}

template <typename type>
void Stack<type>::push(const type &item) {
	Node<type>* current = new Node<type>;
	current->data = item;
	current->next = head;
	head = current;	
	n++;	
}

template <typename type>
type& Stack<type>::top() const {
	if (n > 0) {
		return head->data;
	}
}

template <typename type>
void Stack<type>::pop() {
	if (n > 0) {
		Node<type>* temp = head;
		head = head->next;
		delete(temp);
		n--;
	}
}

template <typename type>
bool Stack<type>::empty() const {
	return n == 0;
}

template <typename type>
int Stack<type>::size() const {
	return n;
}

#endif //STACK_H
