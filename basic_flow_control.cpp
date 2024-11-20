#include <iostream>

/*  This is a basic flow-control example. 
    The following example demonstrates the usage of 
    if-else statment, for loop and while loop in C++. 
*/


int main(){

    // if-else statement 
    int int_input;
    std::cout<<"Please input an integer (it will be truncated to an integer otherwise):";
    std::cin>>int_input;

    if (int_input >= 20)
    {
        std::cout<< "It is greater than or equal to 20"<<std::endl;
        std::cout<<"The input integer is ";
        std::cout<<int_input<<std::endl;
    }
    else if (int_input > 10)
    {
        std::cout<< "It is smaller than 20 but greater than 10"<<std::endl;
        std::cout<<"The input integer is ";
        std::cout<<int_input<<std::endl;
    }
    else{
        std::cout<<"The input integer is ";
        std::cout<<int_input<<std::endl;
    }
    
    // for-loop 
    int sum_record = 0;
    for (int i=0; i<100; i++)
    {
        sum_record += i;
    }

    std::cout<<"The sum (for loop) from 0 to 99 is ";
    std::cout<<sum_record<<std::endl;

    // while-loop 
    int count=0;
    int sum_record_2 = 0;
    while(count<100)
    {
        sum_record_2 += count; 
        count+=1;
    }

    std::cout<<"The sum (while loop) from 0 to 99 is ";
    std::cout<<sum_record<<std::endl;
    
    return 0; 
}