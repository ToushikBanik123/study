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


void replaceElements(Node * &head, int i, int j){
    int count = 0;
    Node * ptr = head;
    Node * prevIthElement = NULL;
    Node * prevJthElement = NULL;
    Node * ithElement = NULL;
    Node * jthElement = NULL;


    while(ptr){
        if(count == i-1){
            prevIthElement = ptr;
            ithElement = ptr->next;
        }
        if(count == j-1){
            prevJthElement = ptr;
            jthElement = ptr->next;
            break;
        }
        ptr = ptr->next;
        count++;
    }

    prevIthElement->next = jthElement;
    prevJthElement->next = ithElement;

    Node * temp = ithElement->next;
    ithElement->next = jthElement->next;
    jthElement->next = temp;
    
}

int main(){
    int i, j;
    Node * head = takeLLInput();

    cout << "Enter the value of i : ";
    cin >> i;

    cout << "Enter the value of j : ";
    cin >> j;

    replaceElements(head,i,j);

    printLL(head);
    return 0; 
}