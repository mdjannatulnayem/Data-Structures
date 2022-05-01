#include "Node.h"
//include the Node class


class Stack{
    private:
    Node *top;

    public:
    Stack(){
        top = NULL;
    }
    //push to the stack
    void push(Node *node){
        node->next = top;
        top = node;
    }

    //pop off the stack
    void pop(){
        Node *node = top;
        top = top->next;
        delete(node);
    }

    //check if empty
    bool isEmpty(){
        if(top == NULL){
            return true;
        }
        return false;
    }

    void traverse(){
        Node *ptr = top;
        while(ptr != NULL){
            std::cout << ptr->data << std::endl;
            ptr = ptr->next;
        }
    }

};

