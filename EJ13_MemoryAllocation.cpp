#include <iostream>
#include <vector>
using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;

struct A
{
public:
    int m_element;
    A(int element) : m_element(element) {};
};

int main()
{
    vector<byte> memory;

    // Memory alloc    
    uint index = memory.size();
    uint new_size = index + sizeof(A);
    memory.resize(new_size);

    // OBJ alloc in memory
    A* obj = new(&memory[index]) A(12);


    // Print
    cout << obj->m_element << " :: " << ((A*)memory.data())[index].m_element << endl;

    // 2nd Memory alloc
    index = memory.size();
    new_size = index + sizeof(A);
    memory.resize(new_size);

    // 2nd OBJ alloc in memory
    obj = new(&memory[index]) A(4);

    // Print
    cout << obj->m_element << " :: " << ((A*)memory.data())[index].m_element << endl;


    // objs in memory print
    for (uint i = 0; i < 2; i++)
    {
        cout << ((A*)memory.data())[i].m_element << endl;
    }
    
    return 0;
}