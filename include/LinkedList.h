#pragma once
#include <iostream>
#include <string>

template <typename T> 
struct Node{
    public:
        T value = 0;
        Node<T>* next = nullptr;

};

template <typename T> 
class LinkedList{
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
    
        Node<T> temp;
        temp.value = data;
        temp.next = nullptr;

        if(head==nullptr){
            head = &temp;
        } else{
            temp.next = head;
            head = &temp;
        }
}

    
};

//Overwrite the << operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll)
{
    Node<T>* currNode = ll.head;
    if(currNode==nullptr){
        os << "Empty List\n";
        return os;
    }
    os << currNode->value;
    return os;
}

//Implementation

