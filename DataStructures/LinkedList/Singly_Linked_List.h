#pragma once
#include <cstddef>
#include <iostream>

using namespace std;

class Node {
public:
	int elem;
	Node* next;

	Node() {
		elem = -1;
		next = NULL;
	}

	Node(int e) { //overloaded constructor
		elem = e;
		next = NULL;
	}
};

class Singly_Linked_List {
private:
	Node* head;
	Node* tail;
	int size;

public:
	Singly_Linked_List() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	Node* getHead() {
		return head;
	}

	Node* getTail() {
		return tail;
	}

	void insertFirst(int elem) {
		//Create the node
		Node* temp = new Node(elem);

		if (head == NULL) { //empty list
			head = temp;
			tail = temp;
			size++;
		}
		else { //non empty list
			temp->next = head; //arrow (->) is used with pointers | dot (.) is used with objects
			head = temp;
			size++;
		}
	}

	void insertLast(int elem) {
		//Create the node
		Node* temp = new Node(elem);

		if (head == NULL) {
			head = temp;
			tail = temp;
			size++;
		}
		else {
			tail->next = temp;
			tail = temp;
			size++;
		}
	}

	void insertAt(int pos, int elem) {

		if (pos < 0 || pos > size)
			cout << "Not a valid position" << endl;
		else if (pos == 0)
			insertFirst(elem);
		else if (pos == size)
			insertLast(elem);
		else {
			Node* temp = new Node(elem);
			Node* current = head;

			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}

			temp->next = current->next;
			current->next = temp;
			size++;
		}
	}

	void deleteFirst() {

		if (head == NULL)
			cout << "List is empty" << endl;
		else {
			Node* temp = head;

			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				delete temp;
				size--;
			}
		}
	}

	void deleteLast() {

		if (head == NULL)
			cout << "List is empty" << endl;
		else {
			Node* temp = tail;
			if (size == 1) {
				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				Node* current = head;

				for (int i = 0; i < size - 2; i++) {
					current = current->next;
				}
				tail = current;
				tail->next = NULL;
				delete temp;
				size--;
			}
		}
	}

	void deleteAt(int pos) {

		if (pos < 0 || pos >= size)
			cout << "Invalid position" << endl;
		else if (pos == 0)
			deleteFirst();
		else if (pos == size - 1)
			deleteLast();
		else {

			Node* current = head;
			for (int i = 0; i < pos - 1; i++) {
				current = current->next;
			}
			Node* temp = current->next;
			current->next = temp->next;
			//current->next = (current->next)->next;
			delete temp;
			size--;

		}
	}

	void deleteWith(int elem) { //print the positions of the nodes with the given element
		/*Node* current = head;
		for (int i = 0; i < size; i++) {
			if (current->elem == elem)
				deleteAt(i);
			current = current->next;
		}*/
		Node* current = head;
		Node* prev = NULL;
		while (current != NULL) {
			if (current->elem == elem) {
				if (current == head) {
					Node* temp = current;
					current = current->next;
					head = current;
					delete temp;
				}
				else if (current == tail) {
					Node* temp = current;
					current = current->next;
					prev->next = current;
					tail = prev;
					delete temp;
				}
				else {
					Node* temp = current;
					current = current->next;
					prev->next = current;
					delete temp;
				}
				size--;
				continue;
			}
			prev = current;
			current = current->next;
		}
	}

	void search(int elem) { //print the positions of the nodes with the given element
		Node* current = head;
		cout << "Positions of the nodes with element " << elem << " : ";
		for (int i = 0; i < size; i++) {
			if (current->elem == elem)
				cout << i << " ";
			current = current->next;
		}
		cout << endl;
	}

	bool searchValue(int elem) { //check whether a given value exist
		Node* current = head;

		while (current != NULL) {
			if (current->elem == elem) {
				cout << "Value found" << endl;
				return true;
			}
			current = current->next;
		}
		return false;
	}

	void print() {
		Node* current = head;

		while (current != NULL) {
			cout << current->elem << " ";
			current = current->next;
		}

		cout << endl;
	}

};

