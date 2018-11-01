// class declaration
#include <iostream>
#include <string>

#ifndef EJ5_CUSTOMCLASS_H
#define EJ5_CUSTOMCLASS_H

class CustomClass{
public:
    // default constructor
    CustomClass();
    // overload constructor (sobreescritura en java)
    CustomClass(std::string, float, float);
    // Destructor
    ~CustomClass();

    // getters
    std::string getName() const;
    float getHeight() const;
    float getWeight() const;

private:
    std::string name;
    float height;
    float weight;
};

#endif
