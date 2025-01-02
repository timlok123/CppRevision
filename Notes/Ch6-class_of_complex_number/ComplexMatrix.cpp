#include "ComplexMatrix.hpp"
#include "ComplexNumber.hpp"

// Initialize as the 0 complex matrix 
ComplexMatrix::ComplexMatrix()
{

    // i. allocate the memory for the array
    mComplexMatrix3x3 = new ComplexNumber* [3];
    for (int i=0; i<3; ++i)
    {
        mComplexMatrix3x3[i] = new ComplexNumber[3];
    }

    // ii. Set the values of the matrix 
    for (int i=0;i<3;++i)
    {
        for (int j=0;j<3;++j)
        {
            mComplexMatrix3x3[i][j] = ComplexNumber();
        }
    }

    //std::cout<< "3x3 complex matrix is created successfully !"<<std::endl;
    
}

// Destructor
// It will be automatically called when the variables leave the scope.
ComplexMatrix::~ComplexMatrix()
{
    for (int i = 0; i < 3; ++i)
    {
        delete[] mComplexMatrix3x3[i];
    }
    delete[] mComplexMatrix3x3;

    // std::cout<<"The destructors is called."<<std::endl;
}

// Assignment operator
ComplexMatrix& ComplexMatrix::operator=(const ComplexMatrix& other)
{
    if (this == &other)
        return *this;

    for (int i = 0; i < 3; ++i)
    {
        delete[] mComplexMatrix3x3[i];
    }
    delete[] mComplexMatrix3x3;

    mComplexMatrix3x3 = new ComplexNumber*[3];
    for (int i = 0; i < 3; ++i)
    {
        mComplexMatrix3x3[i] = new ComplexNumber[3];
        for (int j = 0; j < 3; ++j)
        {
            mComplexMatrix3x3[i][j] = other.mComplexMatrix3x3[i][j];
        }
    }

    return *this;
}

// Overloading the unary/negative (-) operator. It return the negative without modifying the
// current ComplexMatrix operator value. 
ComplexMatrix ComplexMatrix::operator-() const
{
    ComplexMatrix negMatrix;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            negMatrix.mComplexMatrix3x3[i][j] = -mComplexMatrix3x3[i][j];
        }
    }
    return negMatrix;
}

// Overloading + operator. Return the sum of 2 matrix. 
ComplexMatrix ComplexMatrix::operator+(const ComplexMatrix& A) const
{
    ComplexMatrix sumMatrix;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            sumMatrix.mComplexMatrix3x3[i][j] = this->mComplexMatrix3x3[i][j] + 
                                                    A.mComplexMatrix3x3[i][j];
        }
    }

    return sumMatrix;
}

// Overloading + operator. Return the differene of 2 matrix. 
ComplexMatrix ComplexMatrix::operator-(const ComplexMatrix& A) const
{
    ComplexMatrix diffMatrix;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            diffMatrix.mComplexMatrix3x3[i][j] = this->mComplexMatrix3x3[i][j] - 
                                                    A.mComplexMatrix3x3[i][j];
        }
    }

    return diffMatrix;
}

// Overloading * (double) operator. Return the matrix after multiplying the multiple 
ComplexMatrix ComplexMatrix::operator*(double x) const
{
    ComplexMatrix newMatrix;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            newMatrix.mComplexMatrix3x3[i][j] = this->mComplexMatrix3x3[i][j]*x;
        }
    }

    return newMatrix;
}

// Overloading * operator. Return the matrix after multiplying the matrix A
ComplexMatrix ComplexMatrix::operator*(const ComplexMatrix& A) const
{
    ComplexMatrix matMulMatrix;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            matMulMatrix.mComplexMatrix3x3[i][j] = ComplexNumber(); // Initialize to zero
            for (int k = 0; k < 3; ++k)
            {
                matMulMatrix.mComplexMatrix3x3[i][j] = matMulMatrix.mComplexMatrix3x3[i][j] + 
                                                    (this->mComplexMatrix3x3[i][k] * A.mComplexMatrix3x3[k][j]);
            }
        }
    }
    return matMulMatrix;
}
// Raise the matrix to power n (for loop approach)
ComplexMatrix ComplexMatrix::PowerN(int n) const
{
    ComplexMatrix result; // Initialize as the identity matrix
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
                result.mComplexMatrix3x3[i][j] = ComplexNumber(1, 0); // Assuming ComplexNumber has a constructor that takes real and imaginary parts
            else
                result.mComplexMatrix3x3[i][j] = ComplexNumber(0, 0);
        }
    }

    
    ComplexMatrix base = *this;

    for (int i = 0; i < n; i++)
    {
        result = (result * base);
    } 
    
    return result;
}

ComplexMatrix ComplexMatrix::Exp(const ComplexMatrix& A) const
{
    ComplexMatrix result; // Initialize as the identity matrix

    ComplexMatrix term; // Initialize as the identity matrix
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == j)
                term.mComplexMatrix3x3[i][j] = ComplexNumber(1, 0); // Assuming ComplexNumber has a constructor that takes real and imaginary parts
            else
                term.mComplexMatrix3x3[i][j] = ComplexNumber(0, 0);
        }
    }

    result = term; // Start with the identity matrix
    ComplexMatrix power = A; // A^1
    int factorial = 1;
    int cutOffM = 30;

    for (int n = 1; n < cutOffM; ++n) // Sum the series up to n terms
    {
        term = power * (1.0 / factorial);
        result = result + term;
        power = power * A;
        factorial *= (n + 1);
    }

    return result;


}

// Show the 3x3 matrix content 
void ComplexMatrix::ShowMatrix() const
{
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j< 3; ++j){
            std::cout << mComplexMatrix3x3[i][j] << " ,";
        }
        std::cout<<std::endl;
    }

}

// Set the matrix elements as z by specifying matrix's row and col.  
void ComplexMatrix::SetElement(int row, int col, ComplexNumber z)
{
    mComplexMatrix3x3[row][col] = z;
}