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
        
        // Constructors
        ComplexNumber(); 
        ComplexNumber(double x);
        ComplexNumber(double x, double y);
        ComplexNumber(const ComplexNumber& OtherZ); // for others to copy the value from this object 

        std::string description; 
        
        double CalculateModulus() const; // instance of the class would remain const in the function 
        double CalculateArgument() const;
        ComplexNumber CalculatePower(double n) const;

        ComplexNumber& operator=(const ComplexNumber& z); // pass the reference of z to the function
        ComplexNumber operator-() const;
        ComplexNumber operator+(const ComplexNumber& z) const;
        ComplexNumber operator-(const ComplexNumber& z) const;

        friend std::ostream& operator<<(std::ostream& output, 
                                            const ComplexNumber& z);  
        friend double RealPart(const ComplexNumber& z);         // friend function declaration
        friend double ImaginaryPart(const ComplexNumber& z);    // friend function declaration

        double getRealPart() const;
        double getImagPart() const;

        void setRealPart(double x);
        void setImagPart(double y);

        ComplexNumber CalculateConjugate() const;
        void setToConjugate();
};

// You can either choose use friend to access private instance or use the following, 
//std::ostream& operator<<(std:: ostream& output, const ComplexNumber& z);

#endif