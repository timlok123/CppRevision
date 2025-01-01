#ifndef COMPLEXMATRIXHEADERDEF
#define COMPLEXMATRIXHEADERDEF

#include "ComplexNumber.hpp"

class ComplexMatrix
{
    private:
        ComplexNumber** mComplexMatrix3x3;
    
    public:

        // Constructor
        ComplexMatrix();
 
        // Destructor 
        ~ComplexMatrix();

        /*
        ComplexMatrix operator-() const;
        ComplexMatrix operator+(const ComplexMatrix& A) const;
        ComplexMatrix operator-(const ComplexMatrix& A) const;
        ComplexMatrix operator*(const ComplexMatrix& A) const;
        ComplexMatrix operator*(double z) const;
        ComplexMatrix operator/(double z) const;

        ComplexMatrix exp(const ComplexMatrix& A) const;
        */
       
       void ShowMatrix();

};



#endif