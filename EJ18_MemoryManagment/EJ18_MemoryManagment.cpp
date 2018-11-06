#include "EJ18_MemoryManagment_rtcomp.hpp"
#include "EJ18_MemoryManagment_memsys.hpp"

/*
Here we are going to start from the EJ17_RuntimeDatatype and manage the memory for the components.
The BaseComponentMetadata template had the static member SIZE, in this snippet we use that memeber to manage dynamic
allocation of the new type.
See EJ18_MemoryManagment_memsys.hpp for memory system declaration
*/

// Now we create some new components

template<typename T>
struct MyComponent: public Component<MyComponent<T>>
{
    T X;
    T Y;

    MyComponent(T x, T y)
     : X(x), Y(y)
    {}
    
    void print()
    {
        std::cout << "X: " << X << std::endl;
        std::cout << "Y: " << Y << std::endl;
    }

    void printMemory(uint32 ptrMgr)
    {
        std::cout << "Component pointer in manager is: " << ptrMgr << std::endl;
        std::cout << "Component pointer in memory is: " << this << std::endl;
    }
};

typedef MyComponent<float> MyComponentF;

int main()
{
    ComponentManager manager;
    // random init values
    uint32 ptr1 = 32, ptr2 = 48, ptr3 = 64;
    
    {
        MyComponentF compF(2.5f, 3.2f);
        compF.print();
        ptr1 = manager.addComponent<MyComponentF>(&compF);
        std::cout << "1st component added\n";
        MyComponentF compF2(74.1f, -8.9f);
        compF2.print();
        ptr2 = manager.addComponent<MyComponentF>(&compF2);
        std::cout << "2nd component added\n";
    }
    
    std::cout << "\n\n::: Scope memory test :::\n";
    MyComponentF* comp;
    comp = manager.getComponent<MyComponentF>(ptr1);
    comp->printMemory(ptr1);
    comp->print();

    std::cout << "\n\n::: Container memory test :::\n";
    std::cout << "Memory_Size: " << manager.getComponentMemSize<MyComponentF>() << std::endl;    
    std::cout << "Memory_Capacity: " << manager.getComponentMemCapacity<MyComponentF>() << std::endl;
    std::cout << "Component_Count: " << manager.getComponentCount<MyComponentF>() << std::endl;
    manager.deleteComponent<MyComponentF>(ptr1);
    std::cout << std::endl;
    std::cout << "Memory_Size: " << manager.getComponentMemSize<MyComponentF>() << std::endl;    
    std::cout << "Memory_Capacity: " << manager.getComponentMemCapacity<MyComponentF>() << std::endl;    
    std::cout << "Component_Count: " << manager.getComponentCount<MyComponentF>() << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;
    {
        MyComponentF compF(61.f, 149.7f);
        compF.print();
        ptr3 = manager.addComponent<MyComponentF>(&compF);
        std::cout << "3rd component added\n";
        comp = manager.getComponent<MyComponentF>(ptr3);
        comp->printMemory(ptr3);
    }
    std::cout << std::endl;
    std::cout << "Memory_Size: " << manager.getComponentMemSize<MyComponentF>() << std::endl;    
    std::cout << "Memory_Capacity: " << manager.getComponentMemCapacity<MyComponentF>() << std::endl;    
    std::cout << "Component_Count: " << manager.getComponentCount<MyComponentF>() << std::endl;

    std::cout << "\n\n::: Printing all components :::\n";
    comp = manager.getComponent<MyComponentF>(ptr3);
    comp->print();
    comp = manager.getComponent<MyComponentF>(ptr2);
    comp->print();
    std::cout << "PTR1: " << ptr1 << std::endl;
    return 0;
}