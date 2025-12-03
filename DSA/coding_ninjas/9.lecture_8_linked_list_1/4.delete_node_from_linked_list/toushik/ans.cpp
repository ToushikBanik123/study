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

void takeInput(Node *&head){
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

void deletPos(Node * head, int pos){
    Node * headTemp = head;
    for(int i = 0; i < pos; i++){
        if(headTemp == NULL) return;
        headTemp = headTemp->next;
    }
    Node * temp = headTemp->next->next;
    delete headTemp->next;
    headTemp->next = temp;
}

int main(){
    Node * head = NULL;
    int pos;
    cout<< " Enter the elemts of the Linked list and turminate it with (-1) : ";
    takeInput(head);
    printList(head);
    cout << endl << "Enter the indes whear you want to delet the element (pos) : ";
    cin >> pos;
    deletPos(head, pos);
    printList(head);
    return 0;
}