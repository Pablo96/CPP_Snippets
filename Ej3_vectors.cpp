// compile with:
// g++ file_path -std=c++11 -o exe_path
#include <iostream>
#include <vector>

/*------------------
* Vector Functions |
*-------------------
| Element acces |
* front() --> reads vector first element (index 0).
* at(index) --> return element at specified index number.

| Capacity |
* size() --> returns an unsignedd int equal to the number of elements.
* max_size() -> returns the number of elements that can be stored in reserved memory.
* empty() --> returns boolean value if whether vector is empty.
* reserve(N) --> Requests that the vector capacity be at least enough to contain N elements.

| Modifiers |
* push_back(value) --> adds and element to th END of the vector (also resize it).
* insert(index, new_value) --> insert value BEFORE specified index number.
* erase(index) --> removes an element at specified index.
* clear() --> removes all elements in vector.
*/

/*
________
| TIPS |
-------
Can be optimized if you reserve (function reserve(size_t N); ) memory for it befor use
since it will not have to reallocate all its elements every time you add one.
*/

/*_________________________________________________
|                                               |
|  ALWAYS PASS THEM AS REFERENCE TO SAVE MEMORY |
|_______________________________________________|
*/

#define TYPE double

void eraseTest();
void printVector(std::vector<TYPE> &vec);

int main(int argc, char **args){
    // vector<type> name(size)
    eraseTest();    
    return 0;
}

void eraseTest() {
    using namespace std;
    vector<TYPE> vec = vector<TYPE>(4);

    printVector(vec);

    vec[0] = 3.5;
    vec[1] = 16.5;
    vec[2] = 54.0;
    vec[3] = 125.1;

    printVector(vec);
    
    vec.erase(vec.begin() + 1);

    printVector(vec);
}

void printVector(std::vector<TYPE> &vec) {
    using namespace std;

    for (int i = 0; i < vec.size(); i++) {
        try {
            cout << vec[i] << " : " << i << endl;
        } catch (...) {
            cout << "null : " << i << endl;
        }
    }
}