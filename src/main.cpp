#include "..\include\LinkedList.h"

int main(){
    LinkedList<char> stonesList;
    for(char i = 'A'; i<='Z'; i++){
        stonesList.insertAtTail(i);
    }
    std::cout << stonesList;
    
}