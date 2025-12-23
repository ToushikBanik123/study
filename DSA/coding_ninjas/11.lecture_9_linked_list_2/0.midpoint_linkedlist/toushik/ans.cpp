#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
	int data;
	Node * next;
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
};

Node * takeInput(){
    Node * head = NULL;
	Node * tail = NULL;
	int i = 0;
	while(true){
    	cin >> i;
    	if(i == -1) break;
    	if(tail == NULL){
    		head = new Node(i);
    		tail = head;
    	}else{
    		tail->next = new Node(i);
    		tail = tail->next;
    	}
    }
    return head;
}

void printLinkedList(Node * head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}


Node * midNode(Node * head){
    Node * i = head;
    Node * j = head;
    while(true){
        if(j->next == NULL) break;
            j = j->next;
        if(j->next == NULL) break;
            j = j->next;
        if(i->next != NULL){
            i = i->next;
        }
    }
    return i;
}


int main(){
	Node * head = takeInput();
	printLinkedList(head);
	Node * mid = midNode(head);
	cout << "So the mid element in the list is : "<< mid->data;
	return 0;
}