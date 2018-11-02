#include "EJ17_RuntimeDatatypes.hpp"

/*
Lets suppose i need user (By the user i mean framework user) defined components 
And this components are attatched to an Entity (commonly in an ECS system).
This is how i would do it.
*/
uint32 ComponentManager::componentsCounts = 0;

template<class component>
uint32 BaseComponentMetaData<component>::ID = ComponentManager::componentsCounts++;
template<class component>
size_t BaseComponentMetaData<component>::SIZE = sizeof(component);

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