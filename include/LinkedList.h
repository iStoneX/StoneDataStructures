#pragma once
#include <iostream>
#include <string>

template <typename T> 
struct Node{
    public:
        T value;
        Node<T>* next;
        Node():value(0),next(nullptr){};

};

template <typename T> 
class LinkedList{
    public:
        Node<T>* head;
        template <T>
        friend std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll);

    LinkedList():head(nullptr){}
    ~LinkedList(){delete head;}

    void insertAtHead(T data){
        Node<T>* temp = new Node<T>;
        temp->value = data;
        if(head==nullptr){
            head = temp;
        } else{
            temp->next = head;
            head = temp;
        }
    }

    void insertAtTail(T data){
        Node<T>* temp = new Node<T>;
        temp->value = data;
        if(head==nullptr){
            head = temp;
        } else{
            Node<T>* currNode = head;
            while(currNode->next!=nullptr){ currNode = currNode->next; }
            currNode->next = temp;
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
    while(currNode->next!=nullptr){
        currNode = currNode->next;
        os << ',' << ' ';
        os << currNode->value;
    }
    os << '\n';
    return os;
}