// File: swap_integer.cpp
// Author: timlok123 
// Date: November 30, 2024 
// Description: Exercise 5.3. Swap the integers value in the function.

#include <iostream>

void swapIntegerPointer(int* x, int* y);
void swapIntegerReference(int& x, int& y);

int main(){
    
    int x1 = 1, x2 = 2;

    std::cout<< "The value of x1 is " << x1 << std::endl; 
    std::cout<< "The value of x2 is " << x2 << std::endl;

    swapIntegerPointer(&x1, &x2);
    std::cout<< "After swap by pointer, " << std::endl;
    std::cout<< "The value of x1 is " << x1 << std::endl; 
    std::cout<< "The value of x2 is " << x2 << std::endl;

    swapIntegerReference(x1, x2);
    std::cout<< "After swap by reference, " << std::endl;
    std::cout<< "The value of x1 is " << x1 << std::endl; 
    std::cout<< "The value of x2 is " << x2 << std::endl;

    return 0; 
}

void swapIntegerPointer(int* x, int* y){
    int tmp = *x;
    *x = *y;
    *y = tmp; 
}

void swapIntegerReference(int& x, int& y){
    int tmp = x;
    x = y;
    y = tmp;
}
