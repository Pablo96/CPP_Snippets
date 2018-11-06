#pragma once
#include "EJ18_MemoryManagment_common.hpp"
#include "EJ18_MemoryManagment_rtcomp.hpp"
#include <memory>
#include <vector>
#include <map>

class ComponentManager
{
    // every component is stored secuentially in memory according its type
    std::map<uint32, std::vector<byte>> memory;
    // every memory has it own free positions map
    std::map<uint32, std::vector<uint32>> free_map;

public:
    ComponentManager() = default;
    ~ComponentManager() = default;

    template <class T>
    uint32 addComponent(BaseComponent* comp)
    {
        uint32 index;
        
        // If there is a free place in memory we use it
        if (!free_map[T::ID].empty())
        {
            index = free_map[T::ID].back();
            free_map[T::ID].pop_back();
        }
        // Else we resize the memory
        else
        {
            // Since memory is a byte array, the size function returns the size in bytes
            index = (uint32) memory[T::ID].size();
            // So we expand the memory Component::SIZE bytes to store the component
	        memory[T::ID].resize(index + T::SIZE);
        }
        
        // Copy the component in the memory given by "comp" to the pointer
        // new(memory_pointer) Class(const class & other) #VisualStudioOnly?
	    T* component = new(&memory[T::ID][index]) T(*(T*)comp);
        // Return the "pointer" to the component in the memory array.
	    return index;
    }

    template <class T>
    T* getComponent(uint32 comp)
    {
        return (T*) &memory[T::ID][comp];
    }

    template <class T>
    void deleteComponent(uint32 comp)
    {
        T* component = getComponent<T>(comp);
        component->~T();
        free_map[T::ID].push_back(comp);
    }

    template <class T>
    uint32 getComponentMemSize()
    {
        return (uint32) memory[T::ID].size();
    }

    template <class T>
    uint32 getComponentMemCapacity()
    {
        return (uint32) memory[T::ID].size() / T::SIZE;
    }

    template <class T>
    uint32 getComponentCount()
    {
        return getComponentMemCapacity<T>() - (uint32)free_map[T::ID].size();
    }
};
