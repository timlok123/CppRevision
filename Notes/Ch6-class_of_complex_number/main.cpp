#include "ComplexNumber.hpp"

int main()
{
    // Test the constructor
    ComplexNumber z1(4.0, 3.0);
    ComplexNumber z6(4.0);

    std::cout<<"Constructor works well."<<std::endl;
    std::cout<< "z1 is ";
    std::cout<< z1 << std::endl;
    std::cout<< "z6 is ";
    std::cout<< z6 << std::endl;

    // Test the copy constructor
    ComplexNumber z5(z1);
    std::cout << "z5 is " << z5 << std::endl;
    std::cout << "z1 is " << z1 << std::endl;
    z5.setRealPart(10.0);  
    std::cout << "After modifying z5's real part:" << std::endl;  // They should be independent
    std::cout << "z5 is " << z5 << std::endl;
    std::cout << "z1 is " << z1 << std::endl;

    std::cout<< "z1 is ";
    std::cout<< z1 << std::endl;
    std::cout << "The modulus of z = 4 + 3i is ";
    std::cout << z1.CalculateModulus() << std::endl;
    std::cout << "The arguement of z = 4 + 3i is ";
    std::cout << z1.CalculateArgument() << std::endl;

    // Test the power calculation
    ComplexNumber z2;
    z2 = z1.CalculatePower(3);
    std::cout << " z^(3) = (4 + 3i)^(3) is ";
    std::cout << z2 << std::endl;

    ComplexNumber z7(0,0);
    std::cout << "0 to the power 0 is defined as  " << z7.CalculatePower(0) <<std::endl;

    // Test the override + & - function 
    ComplexNumber z3(4,3);
    std::cout << z1 + z3 << std::endl;

    ComplexNumber z4(4,5);
    std::cout << z1 - z4 << std::endl;

    // Check the real part and imaginary part getter & friend function
    std::cout << "The real part of z1 is " << z1.getRealPart() << std::endl;
    std::cout << "The real part of z1 is " << RealPart(z1) << std::endl;

    std::cout << "The imaginary part of z1 is " << z1.getImagPart() << std::endl;
    std::cout << "The imaginary part of z1 is " << ImaginaryPart(z1) << std::endl;

    // Test the conjugate function
    std::cout<< "z1 is " << z1 << std::endl;
    std::cout << "The complex conjugate of z1 is " << z1.CalculateConjugate() << std::endl;

    // Test the setToConjugate function
    z1.setToConjugate();
    std::cout << "After setting z1 to its conjugate, z1 is " << z1 << std::endl;

    return 0; 

}