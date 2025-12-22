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

Node * takeInput(){
    int i = 0;
    Node * head = NULL;
    Node * tail = NULL;
    while(true){
        cin >> i;
        if(i == -1) break;
        if(tail == NULL){
            head = new Node(i);
            tail = head;
        }else{
            tail->next = new Node(i);
            tail = tail->next;
        }
    }
    return head;
}

void printList(Node * head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node * mergeTwoList(Node * i, Node * j){
    if(i == NULL) return j;
    if(j == NULL) return i;
    Node * head = NULL;
    Node * tail = NULL;
    while(true){
        if(i->data < j->data){
            if(tail == NULL){
                head = i;
                tail = i;
            }else{
                tail->next = i;
                tail = tail->next;
            }

            if(i->next == NULL){
                tail->next = j;
                tail = tail->next;
                break;
            }else{
                i = i->next;
            }
        }else{
            if(tail == NULL){
                head = j;
                tail = j;
            }else{
                tail->next = j;
                tail = tail->next;
            }
            if(j->next == NULL){
                tail->next = i;
                break;
            }else{
                j = j->next;
            }
        }
    }
    return head;
}


int main(){
    cout << "Enter the 1st linked list : ";
    Node * t = takeInput();
    cout << "Enter the 2nd linked list : ";
    Node * s = takeInput();
    printList(t);
    printList(s);
    printList(mergeTwoList(s,t));
    return 0;
}