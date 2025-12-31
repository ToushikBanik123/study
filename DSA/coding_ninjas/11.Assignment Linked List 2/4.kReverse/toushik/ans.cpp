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
    Node * tale = NULL;
    int i = 0;

    cout << "Enter the values in your LL : ";
    while(true){
        cin>>i;
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
    cout << "The value inside your LL is : ";
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
}


Node * revrceLL(Node* head, int k){
    if (k <= 0 || head == NULL)
    return head;

    Node * Rh = NULL;
    Node * ptr = head;
    int count = k;

    while(ptr && count){
        Node * temp = ptr->next;
        ptr->next = Rh;
        Rh = ptr;
        ptr = temp;
        count--;
    }

    //Base Case
    if(ptr != NULL) head->next = revrceLL(ptr,k);
    return Rh;
}


int main(){
    Node * head = takeLLInput();
    int n; 

    cout << "Enter the value of n : ";
    cin >> n;
    head = revrceLL(head,n);
    printLL(head);
    return 0;
}