#include <iostream>
using namespace std; 

class Node{
    public:
    int data;
    Node * next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

Node * takeInput(){
    cout << "Enter the elements in the list : ";
    Node * temp = NULL;
    Node * head = NULL;
    int i;
    while(true){
        cin >> i;
        if (i == -1) break;
        if(temp == NULL){
            temp = new Node(i);
            head = temp;
        }
        temp->next = new Node(i);
        temp = temp->next;
    }
    return head;
}

int pritAndCountLinkedList(Node * head){
    int count = 0;
    while(head != NULL){
        cout << head->data << " ";
        head = head -> next;
        count++;
    }
    cout << endl;
    return count;
}

int main(){
    Node * head = takeInput();
    int count = pritAndCountLinkedList(head);
    cout << "The Linkedlist is : " << count << " long." << endl;
    return 0;
}