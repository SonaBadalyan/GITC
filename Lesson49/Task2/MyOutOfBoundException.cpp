#include "MyOutOfBoundException.hpp"
#include <iostream>

 MyOutOfBoundException::MyOutOfBoundException(std::string message, int index, int start, int end)
 {
     this->message = message;
     this->index = index;
     this->start = start;
     this->end = end;
 }

 void MyOutOfBoundException::print() const
 {
     std::cout << this->message << std::endl;
     std::cout << "index: " << index << std::endl;
     std::cout << "start: " << start << std::endl;
     std::cout << "end: " << end << std::endl;
     std::cout << std::endl;
 }