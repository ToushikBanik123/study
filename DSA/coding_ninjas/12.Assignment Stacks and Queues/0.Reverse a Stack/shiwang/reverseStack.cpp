#include<iostream>
using namespace std;

template <typename T>

class stackUsingArray {
	T* data;
	int capacity;
	int next;

public:
	stackUsingArray() {
		capacity = 4;
		next = 0;
		data = new T[capacity];
	}

	void push(T val) {
		if(next == capacity) {
			capacity = capacity * 2;
			T* newData = new T[capacity];
			for(int i = 0; i < next; i++) {
				newData[i] = data[i];
			}
			delete[] data;
			data = newData;
		}
		data[next] = val;
		next++;
	}

	bool isEmpty() {
		return next == 0;
	}

	T pop() {
		if(isEmpty()) {
			cout << "Stack is Empty"<< endl;
			return T();
		}
		next--;
		return data[next];
	}

	T top() {
		if(isEmpty()) {
			cout << "Stack is Empty"<< endl;
			return -1;
		}
		return data[next-1];
	}

	int size() {
		return next;
	}

	~stackUsingArray() {
		delete[] data;
	}
};


void reverseStack(stackUsingArray<int>* s1, stackUsingArray<int>* s2) {
	if(s1->isEmpty() || s1->size() == 1) {
		return;
	}

	int val = s1->pop();
	reverseStack(s1, s2);
	while(!s1->isEmpty()) {
		s2->push(s1->pop());
	}
	s1->push(val);
	while(!s2->isEmpty()) {
		s1->push(s2->pop());
	}
}


int main() {

	int n;
	cin >> n;

	stackUsingArray<int>* s1 = new stackUsingArray<int>();
	stackUsingArray<int>* s2 = new stackUsingArray<int>();

	for(int i = 0; i < n; i++) {
		int data;
		cin >> data;

		s1->push(data);
	}
	cout <<s1->top() <<endl;
	reverseStack(s1, s2);
	cout <<s1->top() <<endl;
	cout <<s2->top() <<endl;



}