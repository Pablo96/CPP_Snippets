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
class MyComponent: public Component<MyComponent<T>>
{
    T X;
    T Y;
public:
    MyComponent(T x, T y)
     : X(x), Y(y)
    {}
    
    void print()
    {
        std::cout << "X: " << X << std::endl;
        std::cout << "Y: " << Y << std::endl;
    }
};


int main()
{
    ComponentManager* manager = ComponentManager::GetInstance();
    std::cout << (uint32) manager << "\t manager2" << (uint32) ComponentManager::GetInstance() << std::endl;


    MyComponent<float> comp(2.5f, 3.2f);
    comp.print();
    comp.printSize();

    std::cout << "every float has " << sizeof(int) <<" bytes" <<
                " and the base component has a 32b" <<
                " pointer which is 4 bytes" << std::endl;

    MyComponent<long long> comp2(42, 611);
    comp2.print();
    comp2.printSize();

    std::cout << "every double has " << sizeof(long long) <<" bytes" <<
                " and the base component has a 32b" <<
                " pointer which is 4 bytes + 4 bytes for padding" << std::endl;

    return 0;
}