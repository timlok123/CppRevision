#include "ComplexMatrix.hpp"
#include "ComplexNumber.hpp"

// Initialize as the Identity complex matrix 
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
            if (i==j)
            {
                mComplexMatrix3x3[i][j] = ComplexNumber(1.0);
                continue; 
            }
            mComplexMatrix3x3[i][j] = ComplexNumber();
        }
    }

    std::cout<< "3x3 complex matrix is created successfully !"<<std::endl;
    
}

// Destructor 
ComplexMatrix::~ComplexMatrix()
{
    for (int i = 0; i < 3; ++i)
    {
        delete[] mComplexMatrix3x3[i];
    }
    delete[] mComplexMatrix3x3;
}

// Show the 3x3 matrix content 
void ComplexMatrix::ShowMatrix(){
    
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j< 3; ++j){
            std::cout << mComplexMatrix3x3[i][j] << " ,";
        }
        std::cout<<std::endl;
    }

}