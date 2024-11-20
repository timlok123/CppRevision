/*  
    The following example demonstrates the usage of 
    STL data structures in C++. 
*/

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

void vector_example();
void unordered_map_example();
void ordered_map_example();

void vector_example() { 
    
    // vector (dynamics array)
    // but it does not have built-in slicing & vectorization operator ! 
    std::vector<double> double_vec = {1.5, 2.0, 3.33};
    double_vec.push_back(6); // add the values to the back of arrays 
    double_vec.push_back(5); 
    double_vec.pop_back();   // pop the last values 

    // Print the index position before each output
    // size_t can be viewed as unsigned integer. Typically used for indexing
    for(size_t i = 0; i < double_vec.size(); ++i) { 
        // cannot directly output vector -> for loop
        std::cout << "Index " << i << ": " << double_vec[i] << std::endl;
    }

    /* Another way to show the values in vector with index */
    /* size_t index_vec = 0; 
    for(const double& vec_value: double_vec) { //const means we would not modify the vector values in this for loop 
        std::cout << "Index " << index_vec << ": " << vec_value << std::endl;
        ++index_vec;
    }*/

}

void unordered_map_example(){ 
    
    // hash-based map 
    // Suitable when order of elements is not important 

    std::unordered_map<std::string, int> unordered_map;
    unordered_map["one"] = 1;
    unordered_map["two"] = 2;
    unordered_map["three"] = 3;

    std::cout << "Unordered Map elements: ";

    // using pair to show the elements in the unordered_map
    for (const auto& pair : unordered_map) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;

}

void ordered_map_example(){

    // tree-based map 
    std::map<int, std::string> ordered_map;
    ordered_map[1] = "one";
    ordered_map[2] = "two";
    ordered_map[3] = "three";

    std::cout << "Ordered Map elements: ";
    for (const auto& pair : ordered_map) {
        std::cout << "{" << pair.first << ": " << pair.second << "} ";
    }
    std::cout << std::endl;
}

int main(){

    //vector_example();
    unordered_map_example();
    ordered_map_example();

    return 0;
}