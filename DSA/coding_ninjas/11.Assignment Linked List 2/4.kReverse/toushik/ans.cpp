#include <iostream>
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

Node * takeLLInput(){
    Node * head = NULL;
    Node * tale = NULL;
    int i = 0;

    cout << "Enter the values in your LL : ";
    while(true){
        cin>>i;
        if(i == -1) return head;
        if(head == NULL){
            head = new Node(i);
            tale = head;
        }else{
            tale->next = new Node(i);
            tale = tale->next;
        }
    }
}

void printLL(Node * head){
    cout << "The value inside your LL is : ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}