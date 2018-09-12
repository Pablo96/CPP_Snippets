#include <iostream>
#include <array>

/*
   - This programs shows how the class array works.
   - It is a class that wraps a plain array and add functionalities like
    sie() to know the size of it.
    - A more flexible and dynamic allocated array is implemented
    in the class vector. (can be seen in EJ3)
*/

const int size = 5;

int main(int argc, char **args){

    // default array int
    int array_int[size];
    array_int[0] = 2;
    array_int[1] = 8;
    array_int[2] = 4;
    array_int[3] = 58;
    array_int[4] = 96;

    // print the array
    for(int i=0; i< size; i++){
        std::cout << array_int[i] << std::endl;
    }

    // array container class.
    std::array<int, size> int_array;

    // print the array
    for(int i=0; i < int_array.size(); i++){
        int_array[i] = i;
        std::cout << int_array[i] << std::endl;
    }

    return EXIT_SUCCESS;
}