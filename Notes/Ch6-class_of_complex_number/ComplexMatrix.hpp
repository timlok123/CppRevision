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

        ComplexMatrix& operator=(const ComplexMatrix& other); // Assignment operator

        ComplexMatrix operator-() const;
        ComplexMatrix operator+(const ComplexMatrix& A) const;
        ComplexMatrix operator-(const ComplexMatrix& A) const;
        ComplexMatrix operator*(const ComplexMatrix& A) const;
        ComplexMatrix operator*(double x) const;
        ComplexMatrix PowerN(int n) const;

        ComplexMatrix Exp(const ComplexMatrix& A) const;
       
        void ShowMatrix() const;
        void SetElement(int row, int col, ComplexNumber z);

};



#endif