#include <iostream>
using namespace std;

class Node{
    public: 
    int data; 
    Node * next;

    Node(int data){
        this-> data = data; 
        this->next = NULL;
    }

};

void takeLinkedListInput(Node *& head){
    Node * temp = head;
    int i;
    cout << "Enter the listes elements : ";
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

void printTheElement(int k, Node * head){
    Node * temp = head;
    for(int i = 0; i < k; i++){
        temp = temp->next;
    }
    cout << temp->data << endl;
}

int main(){
    int n; 
    cin >> n;
    Node * head = NULL;
    takeLinkedListInput(head);
    cout << "The element in the " << n << "'th index is : ";
    printTheElement(n,head);
    return 0;
}