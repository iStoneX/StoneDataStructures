#pragma once
#include <iostream>
#include<cmath>
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

    void reverse(){
        Node<T>* tNode;
        Node<T>* pNode = nullptr;
        
        while(head!=nullptr){
            tNode = head->next;
            head->next = pNode;
            pNode = head;
            head = tNode;
        }
        head = pNode;
    }

    static LinkedList merge(LinkedList<T> A,LinkedList<T> B){
        //merges two sorted lists
        Node<T>* index1 = A.head;
        Node<T>* index2 = B.head;
        LinkedList mergedList;
        while(index1!=nullptr && index2!=nullptr){
            if(index1->value == index2->value){
                mergedList.insertAtTail(index1->value);
                index1 = index1->next;
                mergedList.insertAtTail(index2->value);
                index1 = index2->next;
            } else if(index1->value > index2->value){
                mergedList.insertAtTail(index2->value);
                index2 = index2->next;
            }else if(index1->value < index2->value){
                mergedList.insertAtTail(index1->value);
                index1 = index1->next;
            }
        }
        if(index1==nullptr && index2==nullptr){
            return mergedList;
        }
        if(index1==nullptr && index2!=nullptr){
            while(index1!=nullptr){
                mergedList.insertAtTail(index1->value);
                index1 = index1->next;
            }
            return mergedList;
        }
        if(index1!=nullptr && index2==nullptr){
            while(index2!=nullptr){
                mergedList.insertAtTail(index2->value);
                index2 = index2->next;
            }
            return mergedList;
        }
        return mergedList;
    }


};

//Overwrite the << operator
template <typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& ll)
{
    os << '{';
    Node<T>* currNode = ll.head;
    if(currNode==nullptr){
        os << "Empty List\n";
        return os;
    }
    os << currNode->value;
    while(currNode->next!=nullptr){
        currNode = currNode->next;
        os << " -> ";
        os << currNode->value;
    }
    os << '}' << '\n';
    return os;
}

