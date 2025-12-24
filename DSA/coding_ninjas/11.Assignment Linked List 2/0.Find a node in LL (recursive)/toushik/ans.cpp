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

int coutIndex(Node * head, int  x,int cout){
    if(head == NULL) return -1;
    if(head->data == x) return cout;
    return coutIndex(head->next,x,cout+1);
}


int main(){
    Node * head = takeInputInLL();
    int x; 
    cout << "Enter the element you want to find : ";
    cin >>x;
    cout << coutIndex(head,x,0);
    return 0;
}
