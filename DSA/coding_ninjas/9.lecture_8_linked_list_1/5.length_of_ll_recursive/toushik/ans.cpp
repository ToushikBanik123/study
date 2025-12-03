#include <iostream>
using namespace std;

class Node{
    public:
    int data; 
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void takeListInput(Node *&head){
    Node * temp = head;
    int i = 0;
    while(true){
        cin >> i;
        if(i == -1) break;
        if(temp == NULL){
            temp = new Node(i);
            head = temp;
        }else{
            temp->next = new Node(i);
            temp = temp->next;
        }
    }
}

void printList(Node * head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next;
    }
}

int coutElement(Node * head){
    if(head == NULL) return 0;
    return 1 + coutElement(head->next);
}

int main(){
    Node * head = NULL;
    takeListInput(head);
    printList(head);
    cout << endl << "Pring the element : " << coutElement(head);
    return 0;
}