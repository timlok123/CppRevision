#include "ComplexNumber.hpp"
#include <cmath>

// Override the default constructor 
ComplexNumber::ComplexNumber()
{
    mRealPart = 0.0;
    mImagPart = 0.0; 
    description = "This is a class for ComplexNumber";
}

// Constructor that set z = x + iy 
ComplexNumber::ComplexNumber(double x, double y)
{
    mRealPart = x;
    mImagPart = y; 
    description = "This is a class for ComplexNumber";
}


double ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart + mImagPart*mImagPart); 
}

double ComplexNumber::CalculateArgument() const
{
    return atan2(mImagPart, mRealPart); 
}

// Raise to the power n of z with formula z^n = (r e^(i theta))^n 
// where the real part is r^n cos(n*theta)
//       the imaginary part is r^n sin(n*theta)
ComplexNumber ComplexNumber::CalculatePower(double n) const
{
    double modulus = CalculateModulus();
    double theta   = CalculateArgument();
    double real_part = pow(modulus, n) * cos(n*theta);
    double imag_part = pow(modulus, n) * sin(n*theta);
    return ComplexNumber(real_part, imag_part);
}

// Overloading the assignment (=) operator 
// It allows to assign z2 = z1; 
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& z) 
    // add const to ensure z passed would not be modified 
{
    mRealPart = z.mRealPart; // here takes the copy of the integer value 
    mImagPart = z.mImagPart;
    return *this;            // returning the current object 
}

// Overloading the unary/negative (-) operator. It return the negative without modifying the
// current ComplexNumber value. 
ComplexNumber ComplexNumber::operator-() const
{
    return ComplexNumber(-mRealPart, -mImagPart);
}

// Overloading the binary + operator 
ComplexNumber ComplexNumber::operator+(const ComplexNumber& z) const
{
    return ComplexNumber(mRealPart + z.mRealPart, mImagPart + z.mImagPart); 
}

// Overloading the binary  operator 
ComplexNumber ComplexNumber::operator-(const ComplexNumber& z) const
{
    return ComplexNumber(mRealPart - z.mRealPart, mImagPart - z.mImagPart); 
}

double ComplexNumber::getRealPart() const
{
    return mRealPart;
}

double ComplexNumber::getImagPart() const
{
    return mImagPart;
}

// Overloading insertion << operator
std::ostream& operator<< (std::ostream& output, 
                          const ComplexNumber& z)
{
    // Format as (a + bi) or (a - bi)
    output<< "(" << z.getRealPart() << " ";
    if (z.getImagPart() >= 0.0)
    {
        output<< "+ " <<z.getImagPart() << "i)";
    } 
    else
    {
        output<< "- " <<-z.getImagPart() << "i)";
    }
    return output;
}
