
class Node{ //Generic Node
    public:
    Node(int x){ //constructor
        data = x;
        next = NULL;
    }
    int data; //data

    Node *next; //pointer to next node
};
