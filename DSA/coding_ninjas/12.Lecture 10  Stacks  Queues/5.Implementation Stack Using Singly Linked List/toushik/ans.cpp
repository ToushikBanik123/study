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

class Stack{
    private:
    Node * head; 
    int size;

    public:
    Stack(){
        head = NULL;
        size = 0;
    }

    void push(int data){
        Node * temp = this->head; 
        this->head = new Node(data);
        this->head->next = temp;
        this->size++;
    }

    int pop(){
        if(size == 0) return -1;
        Node * temp = this->head;
        int tempData = temp->data;
        this->head = this->head->next;
        delete temp;
        this->size--;
        return tempData;
    }

    int top(){
        if(size == 0) return -1;
        return this->head->data;
    }

    int size(){
        return size;
    }

    bool isEmpty(){
        return head == NULL;
    }

};

int main(){
    Stack temp;
    temp.push(1);
    cout << temp.pop();
    return 0;
}