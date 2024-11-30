// File: sd_of_array.cpp
// Author: timlok123 
// Date: November 30, 2024 
// Description: Exercise 5.4. Calculate the standard deviation of an array. 

#include <iostream>
#include <cmath>

double calculateMeanArray(double arr[], int size);
double calculateSDArray(double arr[], int size);

int main(){

    double numbers[] = {10.5, 20.3, 30.7, 40.2, 50.1};

    // sizeof() return the actual size of array in computer. Need to divide it by correspoding 
    // data types for getting the size. 
    int size_of_arr = sizeof(numbers)/sizeof(numbers[0]); 

    std::cout<< "The sample S.D. of the array is "; 
    std::cout<< calculateSDArray(numbers,size_of_arr)<<std::endl;

    return 0; 
}


double calculateMeanArray(double arr[], int size){
    double sum1 = 0.0;

    for (int i=0; i<size; i++){
        sum1 += arr[i]/size;
    }

    return sum1;

}

double calculateSDArray(double arr[], int size){
    double sumOfDiffSquare = 0.0;
    double mean = calculateMeanArray(arr,size);

    for (int i=0; i<size; i++){
        sumOfDiffSquare += pow(arr[i] - mean, 2);
    }

    return sqrt(sumOfDiffSquare/ (size-1));

}

