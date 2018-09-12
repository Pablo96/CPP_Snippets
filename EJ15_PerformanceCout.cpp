#include <iostream>
#include <chrono>

using namespace std;

void NoSync();
void Sync();

int main(int argc, char** arv)
{
    unsigned int option = 0;
    do
    {
        cout << "Test noSync=1 Sync=2 exit=0: ";
        cin >> option;

        switch (option)
        {
        case 0: return 0;
        // fast way
        case 1: NoSync(); break;
        // slow way
        case 2: Sync(); break;
        default:
            cout << "please choose a valid option" << endl;
        }
    }while (option);
}

void NoSync()
{
    /*
    setvbuf to make it work with visual studio
    */
    ios_base::sync_with_stdio(false);
    setvbuf(stdout, 0, _IOLBF, 4096);
    auto start = chrono::high_resolution_clock::now();

    unsigned int i = 0;
    while ( i < 2000)
    {
        cout << "DEBUG: i = " << i << "\n";
        i++;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> frameTime = end-start;
    cout<< frameTime.count() << " seconds\n";
}

void Sync()
{
    ios_base::sync_with_stdio(true);
    cout << unitbuf;
    auto start = chrono::high_resolution_clock::now();

    unsigned int i = 0;
    while ( i < 2000)
    {
        cout << "DEBUG: i = " << i << '\n';
        i++;
    }

    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> frameTime = end-start;
    cout<< frameTime.count() << " seconds\n";
}