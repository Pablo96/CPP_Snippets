#include <iostream>
#include <string>

using namespace std;


int main()
{
    string str;
    string str1;

    cout << "File path: ";
    cin >> str1;
    cout << endl;
    
    unsigned int point_pos = (unsigned int) str1.find_last_of('.') + 1;
    string sub = str1.substr(point_pos, str1.size());

    cout << endl << "Path file format: " << sub << endl << endl;

    do
    {
        cout << "File format: ";
        cin >> str;
        cout << endl;
    } while (str.size() != 3);

    unsigned int op = (unsigned int) str[0] +(unsigned int) str[1] +(unsigned int) str[2];

    switch (op)
    {
        case 315:
            cout << "OBJ" << endl;
            break;

        case 320:
            cout << "FBX" << endl;
            break;

        default:
            cout << "DEFAULT" << endl;
            break;

    }

    cin.get();
}