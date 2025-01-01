#include "ComplexNumber.hpp"
#include "ComplexMatrix.hpp"

#include <iostream>

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

    // Test the override + , -, * function 
    std::cout << "Test the +, -, * function"<<std::endl;
    ComplexNumber z3(4,3);
    std::cout << z1 + z3 << std::endl;

    ComplexNumber z4(4,5);
    std::cout << z1 - z4 << std::endl;

    ComplexNumber z8(12.0,13.0);
    std::cout << z1* z8 << std::endl;

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

    // Test the complex matrix construction 
    ComplexMatrix IdentityMatrix;
    
    IdentityMatrix.SetElement(0 , 0 , ComplexNumber(1.0));
    IdentityMatrix.SetElement(1 , 1 , ComplexNumber(1.0));
    IdentityMatrix.SetElement(2 , 2 , ComplexNumber(1.0));
    IdentityMatrix.ShowMatrix();

    // Test the unary -, + , -, * & matrix multiplication operator for ComplexMatrix
    ComplexMatrix negMatrix = -IdentityMatrix;
    std::cout << "The negative of the complex matrix is: " << std::endl;
    negMatrix.ShowMatrix();

    std::cout << "The sum of I and -I is: " << std::endl;
    (negMatrix + IdentityMatrix).ShowMatrix();

    std::cout << "The difference of I and I is: " << std::endl;
    (IdentityMatrix - IdentityMatrix).ShowMatrix();

    std::cout << "The multiple of 10 and I is: " << std::endl;
    (IdentityMatrix*10).ShowMatrix();

    // Test SetElement 
    ComplexMatrix ZComplexMatrix;
    std::cout << "Test SetElement()" << std::endl;
    ZComplexMatrix.SetElement(0 , 0 , z1);
    ZComplexMatrix.SetElement(0 , 2 , z1);
    ZComplexMatrix.SetElement(2 , 0 , z1);
    ZComplexMatrix.SetElement(2 , 2 , z1);
    ZComplexMatrix.ShowMatrix(); 

    // Test matrix multiplication 
    ComplexMatrix matrixA;
    ComplexMatrix matrixB;

    // i. Set elements for matrixA & matrix B (Pauli matrix)
    matrixA.SetElement(0, 0, ComplexNumber(1, 1));
    matrixA.SetElement(0, 1, ComplexNumber(2, 2));
    matrixA.SetElement(1, 0, ComplexNumber(3, 3));
    matrixA.SetElement(1, 1, ComplexNumber(4, 4));

    matrixB.SetElement(0, 1, ComplexNumber(0, -1));
    matrixB.SetElement(1, 0, ComplexNumber(0, 1));

    // ii. matrix multiplication
    std::cout << "matrixA is" << std::endl;
    matrixA.ShowMatrix();
    std::cout << "matrixB is" << std::endl;
    matrixB.ShowMatrix();

    std::cout << "The result of matrixA * I is: " << std::endl;
    ComplexMatrix resultMatrix = matrixA * IdentityMatrix;
    resultMatrix.ShowMatrix();
    
    std::cout << "The result of matrixB * matrixB is: " << std::endl;
    ComplexMatrix resultMatrix2 = matrixB * matrixB;
    resultMatrix2.ShowMatrix();

    // Test PowerN()
    std::cout << "matrixB^5 is" << std::endl;
    ComplexMatrix result3 = matrixB.PowerN(5);
    result3.ShowMatrix();

    return 0; 

}