#include <stdlib.h>
//Requires <stdlib.h>


class dynArray{ //Dynamic Array
    private:
    int *elements = NULL; //container

    int lastIndex; //entry point

    int capacity; //array capacity

    void expandMemory(){ //method to expand memory block!
        capacity++;
        elements=(int*)realloc(elements,capacity*sizeof(int));
    }

    public:
    dynArray(int x){ //constructor
        elements = new int[x];
        if(elements != NULL){
            capacity = x;
            lastIndex = 0;
        }
    }

    ~dynArray(){ //destructor
        delete [] elements;
    }

    //method to add an element
    void addElement(int element){
        if(lastIndex < capacity){
            elements[lastIndex] = element;
            lastIndex++;
        }
        else{
            expandMemory();
            elements[lastIndex] = element;
            lastIndex++;
        }

    }

    //method to remove an element
    //default arguement -1 to remove the last element!
    void removeElement(int index=-1){
        if(index==-1){
            lastIndex--;
            return;
        }
        for(int i=index;i<lastIndex;i++){
            elements[i]=elements[i+1];
        }
        lastIndex--;
    }

    //method to insert an element
    void insertElement(int index,int element){
        if(index > lastIndex){
            return;
        }
        if(lastIndex == capacity){
            expandMemory();
        }
        for(int i=lastIndex;i>index;i--){
            elements[i]=elements[i-1];
        }
        lastIndex++;
        elements[index] = element;
    }

    //method to get size of array
    int sizeofArray(){
        return lastIndex;
    }

    //linear search method
    //**Use binary search when needed!
    int linearSerach(int k){
        for(int i=0;i<=lastIndex;i++){
            if(elements[i] == k){
                return i;
            }
        }
        return -1;
    }

    //method to access an element
    int get(int index){
        if(index < lastIndex){
            return elements[index];
        }
        std::cout << "Error: index out of bound!" << std::endl;
        return -1;
    }

    //print all elements
    void traverse(){
        for(int i=0;i<lastIndex;i++){
            std::cout << elements[i] << std::endl;
        }
    }

};

