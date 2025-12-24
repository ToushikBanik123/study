#include<iostream>
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

void printLL(Node * head){
    cout << "The data insied your linked list : ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

Node * takeInputInLL(){
    Node * head = NULL;
    Node * tale = NULL;
    int i = 0;
    
    cout << "Enter elements in your LL : ";

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

Node * revartALLItrative(Node * head){
    if(head == NULL ||  head->next == NULL) return head;

    Node * i = head;
    Node * j = head->next;
    i->next = NULL;

    while(true){
        if(j->next == NULL){
            j->next = i;
            return j;
        }
        Node * oj = j;
        j = j->next;
        oj->next = i;
        i = oj;
        // i->next = NULL;
    }
}

int main(){
    Node * head = takeInputInLL();
    head = revartALLItrative(head);
    printLL(head);
    return 0;
}