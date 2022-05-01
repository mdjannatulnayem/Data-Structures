
#include "Node.h"
//Must include the Generic Node class!


class LinkedList{
    private:
    Node *head;

    public:
    LinkedList(){ //class constructor
        head = NULL;
    }

    //method to add a node at front
    void addAtFront(Node *node){
        node->next = head;
        head = node;
    }

    //method to check if list empty
    bool isEmpty(){
        if(head == NULL){
            return true;
        }
        return false;
    }

    //method to get the last node
    Node* getLastNode(){
        Node* ptr = head;
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        return ptr;
    }

    //method to add a node at the end
    void addAtEnd(Node *node){
        if(head == NULL){
            head = node;
            node->next = NULL;
        }
        else{
            Node *lastNode = getLastNode();
            lastNode->next = node;
        }
    }

    //method to search a value
    Node* searchList(int k){
        Node *ptr = head;
        while(ptr != NULL && ptr->data != k){
            ptr = ptr->next;
        }
        return ptr;
    }

    //method to delete a node
    Node* deleteNode(int k){
        Node *node = searchList(k);
        Node *ptr = head;
        if(ptr == node){
            head = node->next;
            return node;
        }
        else{
            while(ptr->next != node){
                ptr = ptr->next;
            }
            ptr->next = node->next;
            return node;
        }
    }

    //Method to traverse the list
    void traverseList(){
        Node *ptr = head;
        while(ptr != NULL){
            std::cout << ptr->data << std::endl;
            ptr = ptr->next;
        }
    }
};


//End of class definition
