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

Node * removeElement(Node * head, int n){
    for(int i = 0; i < n; i++){
        if(head == NULL) return NULL;
        Node * temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

Node * finalLL(Node * head, int m , int n){
    if(head == NULL || m == 0) return head;

    Node * RH = head;
    Node * RT = head;

    while(true){
        for(int i = 1; i < m; i++){
            if(RT->next == NULL) return RH;
            RT = RT->next;
        }
        Node * ans = removeElement(RT->next, n);
        RT->next = ans;
        if(ans == NULL) return RH;
        RT = ans; 
    }
}



int main(){
    Node * head = takeLLInput();
    int m,n;
    cout << "Enter the value of m : ";
    cin >> m;
    cout << "Enter the value of n : ";
    cin >> n;
    head = finalLL(head,m,n);
    printLL(head);
    return 0;
}