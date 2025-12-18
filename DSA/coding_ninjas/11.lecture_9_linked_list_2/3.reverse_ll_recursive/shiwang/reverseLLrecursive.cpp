#include<bits/stdc++.h>
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


pair<int, pair<Node*, Node*>> takeInput() {
	int data;
	cin >> data;

	Node* head = NULL;
	Node* tail = NULL;
	int count = 0;

	while(data != -1) {
		Node* node = new Node(data);
		if(head == NULL) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}
		count++;
		cin >> data;
	}
	return {count, {head, tail}};
}

Node* reverseLL(Node* head) {
	if(head->next == NULL) {
		return head;
	}

	Node* node = reverseLL(head->next);
	Node* tail = head->next;
	tail->next  = head;
	head->next = NULL;
	return node;
}


void printLL(Node* head) {

	while(head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	int tc;
	cin >> tc;

	while(tc--) {
		auto input = takeInput();
		Node* head = input.second.first;
		Node* tail = input.second.second;
		int len = input.first;
		head = reverseLL(head);
		printLL(head);
	
	}
}