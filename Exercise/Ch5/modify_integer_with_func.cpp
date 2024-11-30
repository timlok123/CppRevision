// File: modify_integer_with_func.cpp
// Author: timlok123 
// Date: November 30, 2024 
// Description: Exercise 5.2. Modify the integer value in the function. 

#include <iostream>

void modify_integer_pointer(int* x, int y);
void modify_integer_reference(int& x, int y);

int main(){

    int x1 = 1, y1 = 2, x2 = 3, y2 = 4;

    std::cout<< "The value of x1 is " << x1 << std::endl; 
    std::cout<< "The value of x2 is " << x2 << std::endl;      

    modify_integer_pointer(&x1 , y1);
    modify_integer_reference(x2 , y2);

    std::cout<< "After modification, " << std::endl;
    std::cout<< "The value of x1 is " << x1 << std::endl; 
    std::cout<< "The value of x2 is " << x2 << std::endl;      

}


void modify_integer_pointer(int* x, int y){
    // Pass the pointer x, modify it as y value 
    *x = y ; 
}

void modify_integer_reference(int& x, int y){
    // Pass by reference. Modify x value as y value 
    x = y ; 
}
