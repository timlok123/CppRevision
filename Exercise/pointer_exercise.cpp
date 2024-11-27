/* Exercise 4.3 */
#include <iostream>

    // Assign the value to each entries, then delocate it afterwards.
int main(){
 
    double* arr_1 = new double [3];

    for (int i = 0; i < 3; ++i){
        arr_1[i] = i*1.1;
    } 

    for (int i = 0; i < 3; ++i){
        std::cout << "The value in " << i <<" is "<< arr_1[i] << std::endl;
    } 

    delete[] arr_1; // free the array after I use it 

    return 0; 

    


}