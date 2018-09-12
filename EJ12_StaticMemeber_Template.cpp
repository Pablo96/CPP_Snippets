#include <iostream>

template <class T>
struct AClass
{
    static int VALUE;
};

template <class T>
int AClass<T>::VALUE(0);

int main()
{
    using namespace std;

    AClass<int> obj1;
    AClass<double> obj2; //new static values for obj2    
    AClass<int> obj3;   // same static values as obj1 
    obj1.VALUE = 2;
    obj2.VALUE = 5;

    cout << obj1.VALUE << endl;
    cout << obj2.VALUE << endl;
    cout << obj3.VALUE << endl;

    cin.get();

    return 0;
}