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

Node * breakLLInHalf(Node * &head){
    if(head == NULL || head->next == NULL) return NULL;

    Node * slow = head;
    Node * fast = head;

    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node * secondHead = slow->next;
    slow->next = NULL;   // cut at LEFT middle

    return secondHead;
}

Node *  mergeToSortedArray(Node * head1, Node * head2){
    if (!head1) return head2;
    if (!head2) return head1;

    Node * i = head1;
    Node * j = head2;
    Node * headptr = NULL;
    Node * ptr = NULL;

    if(i->data < j->data){
        ptr = i;
        headptr = i;
        i = i->next;
    }else{
        ptr = j;
        headptr = j;
        j = j->next;
    }

    while(i && j){
        if(i->data < j->data){
            ptr->next = i;
            i = i->next;
        }else{
            ptr->next = j;
            j = j->next;
        }
        ptr = ptr->next;
    }
    if (i) ptr->next = i;
    if (j) ptr->next = j;
    return headptr;
}

Node * mergeSort(Node * head){
    if(head->next == NULL) return head;
    Node * head2 = breakLLInHalf(head);
    return mergeToSortedArray(mergeSort(head),mergeSort(head2));
}

int main(){
    Node * head = takeInputInLL();
    head = mergeSort(head);
    printLL(head);
    return 0;
}