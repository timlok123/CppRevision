// File: Newton_method_funcptr.cpp
// Author: timlok123 
// Date: November 30, 2024 
// Description: This file rewrite the content in Newton_method.cpp with function pointer. 
//              Make the code more flexible. 

#include <iostream>
#include <cmath>

double newtonMethod(double (*pFunction) (double),            //f(x)
                    double (*pFunctionDerivative) (double),  //f'(x)
                    double initialGuess,                     
                    double epsilon);

double expFunc1(double x);
double expFunc1Derivative(double x);
double tanFunc1(double x);
double tanFunc1Derivative(double x);

int main(){

    std::cout<< "The Newton's method result is "; 
    std::cout<< newtonMethod(expFunc1,expFunc1Derivative,2,1e-6)<<std::endl;
    // The root is around 1.19367

    std::cout<< "The Newton's method result is "; 
    std::cout<< newtonMethod(tanFunc1,tanFunc1Derivative,1,1e-6)<<std::endl;
    // This function has mutiple roots and its nearest is around 0 

    return 0; 
}

double newtonMethod(double (*pFunction) (double),
                    double (*pFunctionDerivative) (double),
                    double initialGuess,
                    double epsilon)
{
    // The updating formula is x_i+1 = x_i - f(x_i)/f'(x_i)
    // when the |x_i+1 - x_i| < epsilon, the update would stop. 

    double xPrev = initialGuess, xNext = initialGuess + 2 * epsilon;

    while (std::fabs(xNext - xPrev) >= epsilon) {
        xPrev = xNext;
        xNext = xPrev - (*pFunction)(xPrev) / (*pFunctionDerivative)(xPrev);
    }

    return xNext;

}

double expFunc1(double x){
    // e^x + x^3 - 5 
    return std::exp(x) + std::pow(x,3) - 5;
}

double expFunc1Derivative(double x){
    // e^x + 3*x^2 
    return std::exp(x) + 3*std::pow(x,2);
}

double tanFunc1(double x){
    // y = tan(x) - x 
    return std::tan(x) - x;
}

double tanFunc1Derivative(double x){
    // y = sec(x) - 1 = 1/cos(x) - 1 
    return 1/std::cos(x) - 1;
}