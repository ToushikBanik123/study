#include<iostream>
using namespace std;

template <typename T>
class Node {
public:
	T data;
	Node<T>* next;

	Node(T data) {
		this->data = data;
		this->next = NULL;
	}
};

template <typename T>
class queueUsingLL {
	Node<T>* head;
	Node<T>* tail;
	int size;

public:
	queueUsingLL() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	void enqueue(T val) {
		Node<T>* node = new Node<T>(val);
		if(head == NULL) {
			head = node;
			tail = node;
		} else {
			tail->next = node;
			tail = node;
		}
		size++;
	}

	T dequeue() {
		if(empty()) return T();
		Node<T>* temp = head->next;
		T data = head->data;
		delete head;
		head = temp;
		size--;
		return data;
	}

	bool empty() {
		return size == 0;
	}

	int sizeOf() {
		return size;
	}

	T front() {
		if(empty()) return T();
		return head->data;
	}

	~queueUsingLL() {
		while(head!=NULL) {
			Node<T>* temp = head->next;
			delete head;
			head = temp;
		}
	}
};

void reverseQueue(queueUsingLL<int>& q1) {
	if(q1.empty()) return ;

	int data = q1.dequeue();
	reverseQueue(q1);
	q1.enqueue(data);
	return ;
}

int main() {
	int n;
	cin >> n;

	queueUsingLL<int> q1;

	for(int i = 0; i < n; i++) {
		int data;
		cin >> data;
		q1.enqueue(data);
	}
// 	cout << q1.front() << endl;
	reverseQueue(q1);
// 	cout << q1.front() << endl;
	for(int i = 0; i < n; i++) {
		cout << q1.dequeue() << endl;
	}

}