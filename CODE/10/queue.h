#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename type>			
class node {
public:
	type data;
	node<type>* next;
};

template <typename type>
class Queue {

public:
  // Constructor
  explicit Queue();

  // Destructor
  ~Queue();

  // Store new element
  void push(const type& item);

  // Return first element
  type& front() const;

  // Remove first element
  void pop();

  // Return true if empty, false otherwise
  bool empty() const;

  // Number of elements stored
  int size() const;
  
private: 
	node<type>* head;
	int n;

};

// Implement functions below

template <typename type>
Queue<type>::Queue() 
	: head(NULL), n(0) {} 				


template <typename type>
Queue<type>::~Queue() {
	node<type>* current;
	while (head != NULL){
		current = head;
		head = current->next;
		delete current;
	}
	n = 0;
}


template <typename type>
void Queue<type>::push(const type &item) {
	node<type>* temp, * curr;
	temp = new node<type>;
	temp->data = item;
	temp->next = NULL;
	if (head == NULL){
		head = temp;
		head->next = temp->next;	
	}
	else {
		curr = head;
		while (curr->next != NULL){
			curr = curr->next;
		}
		curr->next = temp;
	}
	n++;
}

template <typename type>
type& Queue<type>::front() const {
	if (n > 0) {
		return head->data;
	}
}

template <typename type>
void Queue<type>::pop() {
	if (n > 0) {
		node<type>* temp = head;
		head = head->next;
		delete(temp);
		n--;
}
}

template <typename type>
bool Queue<type>::empty() const {
	return n == 0;
}

template <typename type>
int Queue<type>::size() const {
	return n;
}

#endif //QUEUE_H
