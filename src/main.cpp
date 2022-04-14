#include "..\include\LinkedList.h"

int main(){
    LinkedList<int> stonesList;
    std::cout << stonesList;
    stonesList.insertAtHead(2);
    std::cout << stonesList;
}