#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * prev;

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class Dequeue{
    int count;
    Node * head; 
    Node * tale;

    public: 
    //1. constructor
    Dequeue(){
        //You need to create the appropriate constructor.
        //Size for the queue passed is 10.
        this ->count = 0;
        this->head = NULL;
        this->tale = NULL;
    }
    //2. insertFront
    void insertFront(int data){
        //This function takes an element as input and insert the element at 
        //the front of queue. Insert the element only if queue is not full. 
        //And if queue is full, print -1 and return.
        Node * temp = new Node(data);
        if(this->head == NULL){
            this->head = temp;
            this->tale = temp;
        }else{
            this->head->prev = temp;
            temp->next = this->head;
            this->head = temp;
        }
        count++;    
    }
    //3. insertRear
    void insertRear(int data){
        //This function takes an element as input and insert the element 
        //at the end of queue. Insert the element only if queue is not full. 
        //And if queue is full, print -1 and return.
        Node * temp = new Node(data);
        if(this->head == NULL){
            this->head = temp;
            this->tale = temp;
        }else{
            this->tale->next = temp;
            temp->prev = this->tale;
            this->tale = temp;
        }
        count++;
    }
    //4. deleteFront -
    void deleteFront(){
        //This function removes an element from the front of queue. 
        //Print -1 if queue is empty.
        if(this->head == NULL) return;
        Node * temp = this->head;
        if(count == 1){
            this->head = NULL;
            this->tale = NULL;
        }else{
            this->head = this->head->next;
            this->head->prev = NULL;  
        }
        delete temp;
        count--;
    }
    //5. deleteRear
    void deleteRear(){
        //This function removes an element from the end of queue. 
        if(this->tale == NULL) return;
        Node * temp = this->tale;
        if(count == 1){
            this->tale = NULL;
            this->head = NULL;
        }else{
            tale = this->tale->prev;
            this->tale->next = NULL;
        }
        delete temp;
        count--;
    }
    //6. getFront
    int getFront(){
        // Returns the element which is at front of the queue. 
        // Return -1 if queue is empty.
        if(this->head == NULL){
            return -1;
        }
        return this->head->data;
    }
    //7. getRear
    int getRear(){
        //Returns the element which is at end of the queue. 
        //Return -1 if queue is empty.
        if(this->tale == NULL){
            return -1;
        }
        return this->tale->data;
    }

    int size(){
        return this->count;
    }

    bool empty(){
        return this->count == 0;
    }

    void printDeQueue(){
        Node * ptr = this->head;
        while(ptr){
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    void printRevarcDeQueue(){
        Node * ptr = this->tale;
        while(ptr){
            cout << ptr->data << " ";
            ptr = ptr->prev;
        }
    }
};

int main(){
    return 0;
}