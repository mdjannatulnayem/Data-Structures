#include "Node.h"
//Include the generic Node class

class Queue{
    private:
    Node *front;
    Node *back;

    public:
    Queue(){
        front = back = NULL;
    }

    //add to the queue
    void enqueue(Node *node){
        if(back == NULL){
            front = back = node;
        }
        else{
            back->next = node;
            back = node;
        }
    }

    //remove from the queue
    void dequeue(){
        if(front == NULL){
            return;
        }
        Node *node = front;
        front = front->next;
        if(front == NULL){
            back = NULL;
        }
        delete(node);
    }

    //check if empty
    bool isEmpty(){
        if(front == NULL){
            return true;
        }
        return false;
    }

    void traverse(){
        Node *ptr = front;
        while(ptr != NULL){
            std::cout << ptr->data << std::endl;
            ptr = ptr->next;
        }
    }

};

