#include <iostream>

enum plazas
{
    firstChar = 0,
    secondChar,
    firstInt,
    secondInt = firstInt + 4
};

int main()
{

    /*
    Para que el arreglo se comporte bien cuando se castea a un tipo de dato de mayor tamaño
    el indice se debe pasar como si el arreglo fuera de este ultimo tipo por lo tanto
    si lo que se quiere es ahorrar memoria se debe usar un arreglo que en ambos tipos
    el tamaño se un multiplo del otro.
    */
    char * map = new char(10);

    std::cout << "All char map - size: " << sizeof(map) << std::endl;
    for (int i=0; i < 10; i++)
    {
        map[i] = 'A';
        std::cout << map[i] << std::endl;
    }
    
    std::cout << "first char: " << map[firstChar] << std::endl;
    map[firstChar] = 'B';    
    std::cout << "first char: " << map[firstChar] << std::endl;

    std::cout << "second char: " << map[secondChar] << std::endl;
    map[secondChar] = 'C';
    std::cout << "second char: " << map[secondChar] << std::endl;
    
    int * mapInt = (int*) map;

    std::cout << "first int: " << mapInt[firstInt] << std::endl;
    mapInt[firstInt] = 10500;
    std::cout << "first int: " << mapInt[firstInt] << std::endl;
    
    std::cout << "second int: " << mapInt[secondInt] << std::endl;
    mapInt[secondInt] = 2719;
    std::cout << "second int: " << mapInt[secondInt] << std::endl;

    std::cout << "All char map - size: " << sizeof(mapInt)<< std::endl;
    for (int i=0; i < 10; i++)
    {
        std::cout << map[i] << std::endl;
    }

    std::cout << ":: Comparing the addreses ::" << std::endl;
    std::cout << "Beginning: " << std::endl;    
    std::cout << "map: " << (void*)map;    
    std::cout << "\tmapInt: " << mapInt << std::endl;
    std::cout << "FirstInt: " << std::endl;
    std::cout << "map: " << (void * ) &map[firstInt];
    std::cout << "\tmapInt: " << &mapInt[firstInt] << std::endl;
    std::cout << "SecondInt: " << std::endl;
    std::cout << "map: " << (void * ) &map[secondInt];
    std::cout << "\tmapInt: " << &mapInt[secondInt] << std::endl;
    
    std::cin.get();
}