/*  
    This is a basic pointer usage example. 
    The following example demonstrates the usage of 
    basic pointer and some modern C++ features 
*/

#include <iostream>
#include <memory>     // for using modern C++ memory management 

void stack_allocated_memory(){
    /* 
        This function is used to demonstrate the use of stack allocated memory, 
        they are usually only within the scope of the function.  
    */

    int x = 6;       
    double y = 3.14; 
    
    int* ptr_x;
    ptr_x = &x;    // Assign the address to the ptr. 
                   // Use &x can show the address of x 
                   // Use *ptr_x call the value stored in the address of ptr_x
    
    double* ptr_y = &y;
    
    std::cout << *ptr_x + *ptr_y << std::endl;

    *ptr_x = 100;  // change the value of x with pointer 

    std::cout << *ptr_x + *ptr_y << std::endl;

}

void heap_allocated_memory(){
    /* 
        This function is used to demonstrate the use of heap allocated memory, 
        they are usually global and the lifetime is usually determined by us. 
    */

    double* may;
    may = new double[20];
    
    // Assign values to the array
    for (int i = 0; i < 20; ++i) {
        may[i] = i * 1.1;    // Assign some values
    }
    
    // Print the values
    for (int i = 0; i < 20; ++i) {
        std::cout << may[i] << " ";
    }

    std::cout << std::endl;
    
    // Delete the array
    delete[] may;
    
}

void unique_ptr_example() {

    // unique_ptr - designed against pointer aliasing 

    int x = 10; 

    std::unique_ptr<int> unique_ptr = std::make_unique<int>(x);       // create a new pointer using make_unique
    std::cout << "Value of unique_ptr: " << *unique_ptr << std::endl;  // access the value the same as raw pointer 

    // unique_ptr cannot be copied, but it can be moved
    std::unique_ptr<int> moved_ptr = std::move(unique_ptr);
    if (!unique_ptr) {
        std::cout << "unique_ptr is now null after move." << std::endl;
    }
    std::cout << "Value of moved_ptr: " << *moved_ptr << std::endl;
}

void shared_ptr_example() {

    // unique_ptr - designed to ensure every new has delete 

    std::shared_ptr<int> shared_ptr_1 = std::make_shared<int>(20);
    std::cout << "Value of shared_ptr_1: " << *shared_ptr_1 << std::endl;
    std::cout << "shared_ptr_1 use count: " << shared_ptr_1.use_count() << std::endl;

    // shared_ptr can be  & it increase the use count 
    std::shared_ptr<int> shared_ptr_2 = shared_ptr_1;
    std::cout << "Value of shared_ptr_2: " << *shared_ptr_2 << std::endl;

    std::cout << "shared_ptr_1 use count after copy: " << shared_ptr_1.use_count() << std::endl;
    std::cout << "shared_ptr_2 use count: " << shared_ptr_2.use_count() << std::endl;

}


int main(){


    //stack_allocated_memory();
    //heap_allocated_memory();
    //unique_ptr_example();
    shared_ptr_example();

    return 0; 
}

