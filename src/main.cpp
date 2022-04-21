#include "..\include\LinkedList.h"

int main(){
    LinkedList<int> testList;
    LinkedList<int> testList2;
    testList.insertAtTail(1);
    testList.insertAtTail(3);
    testList.insertAtTail(5);
    testList2.insertAtTail(2);
    testList2.insertAtTail(4);
    testList2.insertAtTail(6);
    
    std::cout << "ListA: " << testList;
    std::cout << "ListB: " << testList2;
    LinkedList<int> testList3 = LinkedList<int>::merge(testList, testList2);
    std::cout << "merge(): " << testList3;
    
}