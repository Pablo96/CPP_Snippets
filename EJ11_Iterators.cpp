#include <iostream>
#include <unordered_map>
#include <string>
#include <typeinfo>

using namespace std;

void printRepeated(bool repeated)
{
    if (!repeated)
        cout << "repeated" << endl << endl;
    else
        cout << "first of it class" << endl << endl;
}

int main()
{
    unordered_map<string, int> map;

    using iterator = unordered_map<string, int>::iterator;

    pair<iterator, bool> resultInsert =  map.emplace("hola", 22);

    printRepeated(resultInsert.second);

    cin.get();

    resultInsert =  map.emplace("hola", 23);

    printRepeated(resultInsert.second);

    cout << resultInsert.first->second << endl;


    return 0;
}