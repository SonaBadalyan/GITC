#include <iostream>
#include "LinkedList.hpp"

int main()
{
    LinkedList<int> list;

    list.add(10);
    list.add(20);
    list.addFront(0);
    list.addFront(-10);
    list.add(30);
    list.add(60);
    
    list.print();
    list.reversePrint();
    
    std::cout << "Is empty " << list.isEmpty() << std::endl;
    
    list.insert(4, 40);
    list.print();
    list.insert(5, 50);
    list.print();
    
    std::cout << list.removeByValue(0) << std::endl;
    list.print();
    
    list.remove(5);
    list.print();
    
    list.deleteFront();
    list.print();

    list.deleteBack();
    list.print();
    
    std::cout << "list[5] " << list[5] << std::endl;
    std::cout << "list[0] " << list[0] << std::endl;
    std::cout << "list[3] " << list[3] << std::endl;
    std::cout << "ist[4] " << list[4] << std::endl;
    
    std::cout << "list.find(10) " << list.find(10) << std::endl;
    std::cout << "list.find(20) " << list.find(20) << std::endl;
    std::cout << "list.find(-10) " << list.find(-10) << std::endl;
    std::cout << "list.find(100) " << list.find(100) << std::endl;
    
    std::cout << list.length() << std::endl;

    LinkedList<int> list1(list);
    list1.print();
    list.print();
    
    std::cout << "list1 == list : " << (list1 == list) << std::endl;
 
    // list.deleteBack();
    // list.deleteBack();
    // list.deleteFront();
    // list.deleteFront();
    
    std::cout << "list1 == list : " << (list1 == list) << std::endl;
    std::cout << list.length() << std::endl;
    
    return 0;
}