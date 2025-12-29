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

Node * takeInput(){
    cout << "Enter the elements in your LL : ";

    Node * head = NULL;
    Node * tale = NULL;
    int i = 0;

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
    cout << "Data inside your LL : ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

void bubleSort(Node * &head){
    if (!head || !head->next) return;

    Node *ptrLimit = NULL;

    while (ptrLimit != head) {
        Node *ptr = head;
        Node *lastPtr = NULL;

        while (ptr->next != ptrLimit) {

            if (ptr->data > ptr->next->data) {
                Node *nextNode = ptr->next;

                // swap
                if (lastPtr == NULL) {
                    ptr->next = nextNode->next;
                    nextNode->next = ptr;
                    head = nextNode;
                    lastPtr = nextNode;
                } else {
                    lastPtr->next = nextNode;
                    ptr->next = nextNode->next;
                    nextNode->next = ptr;
                    lastPtr = nextNode;
                }
                // DO NOT MOVE ptr HERE
            }
            else {
                lastPtr = ptr;
                ptr = ptr->next;
            }
        }
        ptrLimit = ptr;
    }
}


int main(){
    Node * head = takeInput();
    bubleSort(head);
    printLL(head);
    return 0;
}