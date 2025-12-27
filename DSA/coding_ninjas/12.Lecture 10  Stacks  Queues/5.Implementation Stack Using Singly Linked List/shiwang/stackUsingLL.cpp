#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

class stackUsingLL {
	Node* head;
	int length;

public:
	stackUsingLL() {
		head = NULL;
		length = 0;
	}


	void push(int data) {
		Node* node = new Node(data);
		node->next = head;
		head = node;
		length++;

	}

	int pop() {
		if(isEmpty()) return -1;
		Node* node = head;
		head = head->next;
		node->next = NULL;
		int data = node->data;
		length--;
		delete node;
		return data;
	}

	int top() {
		if(isEmpty()) return -1;
		return head->data;
	}

	bool isEmpty() {
		return length == 0;
	}

	int size() {
		return length;
	}

	~stackUsingLL() {
		while (head != NULL) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}

};

int main() {
	stackUsingLL* st1 = new stackUsingLL();

	cout << st1->size()<< endl;
	cout << st1->isEmpty()<< endl;
	cout << st1->pop()<< endl;
	st1->push(2);
	st1->push(5);
	st1->push(8);
	st1->push(6);
	cout << st1->top()<< endl;
	cout << st1->pop()<< endl;
	cout << st1->pop()<< endl;
	cout << st1->top()<< endl;
}