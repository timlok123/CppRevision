/*  Exercise 2.6 */

#include <iostream>
#include <cmath>
#include <iomanip>   // for the std::setprevision() function 

double func(double x){
    return std::exp(x) + std::pow(x,3) - 5;
}

double func_derivative(double x){
    return std::exp(x) + 3*std::pow(x,2);
}

// A for loop version 
double Newton_method_for_loop(double initial_guess, int iteration){

    double x_prev = initial_guess, x_next;
    for (int i = 0; i < iteration; i++){
        x_next = x_prev - func(x_prev)/func_derivative(x_prev); 
        x_prev = x_next;
    }

    return x_next;

}

// A while loop version 
double Newton_method_while_loop(double initial_guess, double epsilon){

    double x_prev = initial_guess, x_next = initial_guess + 2 * epsilon;
    int count = 0;

    while (std::fabs(x_next - x_prev) >= epsilon) {
        x_prev = x_next;
        x_next = x_prev - func(x_prev) / func_derivative(x_prev);
    }

    return x_next;

}

int main(){

    // The root is around 1.19367
    std::cout<< std::setprecision(10) << Newton_method_for_loop(2,100) << std::endl;
    std::cout<< std::setprecision(10) << Newton_method_while_loop(2,1e-5) << std::endl;

    return 0; 
}