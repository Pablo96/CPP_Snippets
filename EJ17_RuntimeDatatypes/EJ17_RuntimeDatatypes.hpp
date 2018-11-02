#pragma once
#include <iostream>

/*
Lets suppose i need user (By the user i mean framework user) defined components 
And this components are attatched to an Entity (commonly in an ECS system).
This is how i would do it.
*/
typedef unsigned int uint32;

// keep count of the components
struct ComponentManager{
    static uint32 componentsCounts;
};

struct BaseComponent
{
    void* entityID; //pointer to the entity is attatched to
};


template <class component>
struct BaseComponentMetaData: public BaseComponent
{
static uint32 ID;
static size_t SIZE;
};


// This could be BaseComponentMetaData but for naming convention we add this dummy
template <class T>
struct Component: public BaseComponentMetaData<T>
{
    void printSize()
    {
        std::cout << "ComponentID " << ID << "\thas size " << SIZE << " Bytes" << std::endl;
    }
};

