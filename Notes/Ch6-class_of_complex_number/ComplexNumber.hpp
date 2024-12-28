#ifndef COMPLEXNUMBERHEADERDEF // Usually is <objectname>HEADEREDF
#define COMPLEXNUMBERHEADERDEF 

#include <iostream>
#include <string>

class ComplexNumber
{
    private:
        double mRealPart; // add m before the private instance variables 
        double mImagPart;
    
    public:
        ComplexNumber(); // constructor 
        ComplexNumber(double x, double y);
        
        double CalculateModulus() const; // instance of the class would remain const in the function 
        double CalculateArgument() const;
        ComplexNumber  CalculatePower(double n) const;

        ComplexNumber& operator=(const ComplexNumber& z); // pass the reference of z to the function
        ComplexNumber operator+() const;
        ComplexNumber operator-() const;

        friend std::ostream& operator<<(std::ostream& output, 
                                            const ComplexNumber& z);    

        std::string description; 
};

#endif