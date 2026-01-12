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
    Node * tail = NULL;
    int i = 0;
    cout << "Enter the value of the LL : ";
    while(true){
        cin >> i;
        if(i == -1) return head;
        Node * temp = new Node(i);
        if(head == NULL){
            head = temp;
            tail = head;
        }else{
            tail->next = temp;
            tail = tail->next;
        }
    }
}

void printLL(Node * head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}

int incrementTheData(Node * &head){
    if(head->next == NULL){
        int temp = head->data +1;
        head->data = temp %10;
        return temp/10;
    }
    int temp = head->data + incrementTheData(head->next);
    head->data = temp % 10;
    return temp/10;
}

int main(){
    Node * head = takeLLInput();
    if(incrementTheData(head)){
        Node * temp = new Node(1);
        head->data = head->data%10;
        temp->next = head;
        head = temp;
    };
    printLL(head);
    return 0;
}