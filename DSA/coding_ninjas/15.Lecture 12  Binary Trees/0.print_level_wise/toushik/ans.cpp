#include <iostream>
#include <queue>
using namespace std; 

template <typename T>
class Node{
    public:
    T data;
    Node<T> * l;
    Node<T> * r;
    
    Node(T data){
        this->data = data; 
        l = NULL;
        r = NULL;
    }
    ~Node(){
        if(l) delete l;
        if(r) delete r;
    }
};

template <typename T>
Node<T> * takeInput(){
    T rootNodeData;
    cin >> rootNodeData;
    if(rootNodeData == -1) return NULL;
    Node<T> * rootNode = new Node<T>(rootNodeData);

    queue<Node<T> *> q;
    q.push(rootNode);

    while(!q.empty()){
        Node<T> * curentNode = q.front();
        q.pop();

        T leftData;
        cin>> leftData;
        if(leftData != -1){
            curentNode->l = new Node<T>(leftData);
            q.push(curentNode->l);
        }
        T rightData;
        cin>> rightData;
        if(rightData != -1){
            curentNode->r = new Node<T>(rightData);
            q.push(curentNode->r);
        }

    }
    return rootNode;
}

template <typename T>
Node<T> * takeBinaryListInput(){
    T rootNodeData;
    cin >> rootNodeData;
    if(rootNodeData == -1) return NULL;

    Node<T> * rootNode = new Node<T>(rootNodeData);
    queue<Node<T> *> storage;
    storage.push(rootNode);

    while(!storage.empty()){
        Node<T> * curentNode = storage.front();
        storage.pop();

        T l;
        T r;

        cin >> l;
        cin >> r;

        if(l != -1){
            curentNode->l = new Node<T>(l);
            storage.push(curentNode->l);
        }
        if(r != -1){
            curentNode->r = new Node<T>(r);
            storage.push(curentNode->r);
        }
    }

    return rootNode;
}

template <typename T>
void printList(Node<T> * rootNode){
    if(!rootNode) return;

    queue<Node<T> * > storage;
    storage.push(rootNode);

    while(!storage.empty()){
        Node<T> * curentNode = storage.front();
        storage.pop();
        cout << curentNode->data << ":";
        if(curentNode->l){
            storage.push(curentNode->l);
            cout << "L:" << curentNode->l->data << ",";
        }else{
            cout << "L: -1,";
        }
        if(curentNode->r){
            storage.push(curentNode->r);
            cout << "R:" << curentNode->r->data << endl;
        }else{
            cout << "R: -1" << endl;
        }
    }
}

int main(){
    Node<int> * rootNode = takeInput<int>();
    printList<int>(rootNode);
    delete rootNode;
    return 0;
}