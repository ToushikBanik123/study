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
    cout << "Entering elements in your linked list end it with(-1) : ";
    int i = 0;
    Node * head = NULL;
    Node * tale = NULL;
    while(true){
        cin>>i;
        if(i == -1) return head;
        if(head == NULL){
            Node * temp = new Node(i);
            head = temp;
            tale = temp;
        }else{
            tale->next = new Node(i);
            tale = tale->next;
        }
    }
}

void printLL(Node * head){
    cout << "Data inside your Linked List : ";
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


Node * arangeTheList(Node * head){
    Node *oddHead = NULL;
    Node *oddTail = NULL;
    Node *evenHead = NULL;
    Node *evenTail = NULL;

    while(head){
        if(head->data %2 == 0){
            //Even Element 
            if(evenHead == NULL){
                evenHead = head;
                evenTail = head;
            }else{
                evenTail->next = head;
                evenTail = evenTail->next;
            }
        }else{
            //Odd element
            if(oddHead == NULL){
                oddHead = head;
                oddTail = head;
            }else{
                oddTail->next = head;
                oddTail = oddTail->next;
            }
        }
        head = head->next;
    }
    if(oddTail) oddTail->next = NULL;
    if(evenTail) evenTail->next = NULL;
    if(oddHead == NULL) return evenHead;
    if(evenHead == NULL) return oddHead;
    oddTail ->next = evenHead;
    return oddHead;
}

int main(){
    Node * head = takeInputInLL();
    printLL(arangeTheList(head));
    return 0;
}
