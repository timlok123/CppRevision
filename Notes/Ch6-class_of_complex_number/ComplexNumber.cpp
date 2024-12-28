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

ComplexNumber::CalculateModulus() const
{
    return sqrt(mRealPart*mRealPart + mImagPart*mImagPart); 
}

ComplexNumber::CalculateArgument() const
{
    return atan2(mImagPart, mRealPart); 
}

// Complete the rest later 
