#include "..\include\LinkedList.h"

int main(){
    LinkedList<char> stonesList;
    stonesList.insertAtHead('B');
    stonesList.insertAtTail('L');
    stonesList.insertAtTail('A');
    stonesList.insertAtTail('K');
    stonesList.insertAtTail('E');
    stonesList.insertAtTail('G');
    stonesList.insertAtTail('A');
    stonesList.insertAtTail('Y');
    std::cout << stonesList;
    
}