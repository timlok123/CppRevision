#include "ComplexNumber.hpp"

int main()
{
    ComplexNumber z1(4.0, 3.0);

    std::cout<<"Constructor works well."<<std::endl;

    std::cout<< "z1 is ";
    std::cout<< z1 << std::endl;
    std::cout << "The modulus of z = 4 + 3i is ";
    std::cout << z1.CalculateModulus() << std::endl;
    std::cout << "The arguement of z = 4 + 3i is ";
    std::cout << z1.CalculateArgument() << std::endl;

    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << " z^(3) = (4 + 3i)^(3) is ";
    std::cout << z2 << std::endl;

    ComplexNumber z3(4,3);
    std::cout << z1 + z3 << std::endl;

    ComplexNumber z4(4,5);
    std::cout << z1 - z4 << std::endl;

    return 0; 

}