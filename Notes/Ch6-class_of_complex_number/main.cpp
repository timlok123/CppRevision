#include "ComplexNumber.hpp"

int main()
{
    ComplexNumber z1(4.0, 3.0);

    std::cout << z1.CalculateModulus() << std::endl;
    std::cout << z1.CalculateArgument() << std::endl;

    // using the pointer to access public variables as well 

    return 0; 

}