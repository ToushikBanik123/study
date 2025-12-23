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

Node * takeInputInLL(){
    cout << "Enter the elememnts in your LL ending by (-1) : ";

    Node* head = NULL;
    Node * tale = NULL;

    int i;

    while(true){
        cin >> i;
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
    cout << "Your Linked List : ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

Node * revarceALLL(Node * head){
    if(head->next == NULL) return head;
    Node * tempHead = revarceALLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return tempHead;
}


int main(){
    Node * head = takeInputInLL();
    head = revarceALLL(head);
    printLL(head);
    return 0;
}