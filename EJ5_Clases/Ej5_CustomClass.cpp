#include "Ej5_CustomClass.h"

CustomClass::CustomClass(){
    // Constructor
    height = 0;
    weight = 0;
}

CustomClass::CustomClass(std::string new_name, float new_height, float new_weight){
    name = new_name;
    height = new_height;
    weight = new_weight;
}

CustomClass::~CustomClass(){

}

std::string CustomClass::getName() const {
    return name;
}

float CustomClass::getHeight() const{
    return height;
}
float CustomClass::getWeight() const{
    return weight;
}