#include "Headers/Structures.h"

int main() {
    List<int> myList;
    
    myList.append(69);
    myList.prepend(1);
    myList.display();
    myList.clear();

    myList.prepend(420);
    myList.display();
    myList.clear();

    for(int i = 1; i <= 10; ++i) 
        myList.append(i ^ (i & (-i)));
    myList.display();
    
    myList.remove(0, 1);
    myList.display();
}