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
    testList3.reverse();
    std::cout << "reverse(): " << testList3;
    std::cout << "------------------------------\n";
    LinkedList<int> testList4;
    testList4.insertAtTail(5);
    testList4.insertAtTail(1);
    testList4.insertAtTail(3);
    std::cout << "ListC: " << testList4;
    testList4.sort();
    std::cout << "sort(): " << testList4;
    
}