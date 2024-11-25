/*  
    This is a basic flow control example. 
    The following example demonstrates the usage of 
    if-else statment, for loop and while loop in C++. 
*/

#include <iostream>
#include <cmath>

double func(double x){
    return std::exp(x) + std::pow(x,3) + 5;
}

double func_derivative(double x){
    return std::exp(x) + 3*x*std::pow(x,2);
}


int main(){

    double x = 2.0; 
    cout<<func(x)<<endl;
    cout<<func_derivative(x)<<endl;

    return 0; 
}