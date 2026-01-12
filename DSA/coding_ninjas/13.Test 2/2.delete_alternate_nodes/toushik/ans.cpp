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

Node * takeInput(){
    Node * head = NULL;
    Node * tale = NULL;
    int i;
    cout << "Enter the elements in your Linked List : ";
    while(true){
        cin >> i;
        if(i == -1) return head;
        Node * temp = new Node(i);
        if(head == NULL){
            head = temp;
            tale = temp;
        }else{
            tale->next = temp;
            tale = tale->next;
        }
    }
}

void printList(Node * head){
    cout << "Your data in the Linked List is : ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

void terimList(Node * &head){
    Node * ptr = head;
    while(ptr != NULL && ptr->next != NULL){
        Node * temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
        ptr = ptr->next;
    }

}

int main(){
    Node * head = takeInput();
    terimList(head);
    printList(head);
    return 0;
}