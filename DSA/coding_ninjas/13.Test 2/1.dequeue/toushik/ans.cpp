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
}

class Dequeue{
    int size;
    Node * head; 
    Node * tale;

    public: 
    //1. constructor
    Dequeue(){
        //You need to create the appropriate constructor.
        //Size for the queue passed is 10.
        this ->size = 0;
        this->head = NULL;
        this->tale = NULL;
    }
    //2. insertFront
    void insertFront(int data){
        //This function takes an element as input and insert the element at 
        //the front of queue. Insert the element only if queue is not full. 
        //And if queue is full, print -1 and return.
        
    }
    //3. insertRear
    void insertRear(int data){
        //This function takes an element as input and insert the element 
        //at the end of queue. Insert the element only if queue is not full. 
        //And if queue is full, print -1 and return.

    }
    //4. deleteFront -
    void deleteFront(){
        //This function removes an element from the front of queue. 
        //Print -1 if queue is empty.
    }
    //5. deleteRear
    void deleteRear(){
        //This function removes an element from the end of queue. 
    }
    //6. getFront
    int getFront(){
        // Returns the element which is at front of the queue. 
        // Return -1 if queue is empty.
    }
    //7. getRear
    int getRear(){
        //Returns the element which is at end of the queue. 
        //Return -1 if queue is empty.
    }
}

int main(){
    return 0;
}