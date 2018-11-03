#pragma once
#include <iostream>
#include "EJ18_MemoryManagment_common.hpp"


// keep count of the components
static uint32 componentsCounts = 0;

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

template<class component>
uint32 BaseComponentMetaData<component>::ID = componentsCounts++;
template<class component>
size_t BaseComponentMetaData<component>::SIZE = sizeof(component);