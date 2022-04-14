#pragma once
#include <iostream>
#include <string>

//Declarations

template <typename T> class Node{
    public:
        T value = 0;
        Node<T>* next = nullptr;

};

template <typename T> class LinkedList{
    public:
        Node<T>* head;

        template <T>
        friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll);
    

    LinkedList(){
        head=nullptr;
    }

    ~LinkedList(){
        delete head;
    }

    void insertAtHead(T data){
    
        Node<T>* temp = new Node<T>;
        temp->value = data;

        if(head==nullptr){
            head = temp;
        } else{
            temp->next = head;
            head = temp;
        }
        delete temp;
}

    
};

//Overwrite the << operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll)
{
    Node<T>* currNode = ll.head;
    if(currNode==nullptr){
        os << "Empty List";
        return os;
    }
    os << scanf("%d",currNode->value);
    return os;
}

//Implementation

