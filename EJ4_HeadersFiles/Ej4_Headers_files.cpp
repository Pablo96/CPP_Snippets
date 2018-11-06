// uses C++11
#include "Ej4_Headers_files.h"

int main(int argsc, char **args){
    using namespace std;

    vector<float> vecA, vecB;
    vecA.push_back(2.0);
    vecA.push_back(5.0);
    vecA.push_back(-4.0);
    showArray(vecA);
    vecB.push_back(1.0);
    vecB.push_back(-5.0);
    vecB.push_back(-8.0);
    showArray(vecB);
    cout << dotProduct(vecA, vecB) << endl;

    return EXIT_SUCCESS;
}

float dotProduct(std::vector<float> &vec1, std::vector<float> &vec2){
    if (vec1.size() != vec2.size())
        throw std::invalid_argument("Different sizes vectors.");
    float sum=0;

    for (int i=0; i < vec1.size(); i++, sum+=vec1.at(i)*vec2.at(i));

    return sum;
}

template<typename v_type>
void showArray(std::vector<v_type> &v){
    int max = v.size() - 1;
    for(auto element : v){
        std::cout << element;
        if (element != v.at(max)){
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}