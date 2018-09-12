#include <iostream>
#include <thread>

using namespace std;

class Test
{
public:
    
    Test()
    {
        thPtr = new thread(&Test::func1, this);
    }
    void func1()
    {
        cout << "thread " << this_thread::get_id() << endl;    
        cin.get();
    }
    
    thread * thPtr;
};

int main()
{
    Test test;
    cout << "::main::" << endl << endl;

    test.thPtr->join();

    cout << "main exited..." << endl << endl;    
    return 0;
}
/*
int main()
{

    thread thread1(func1);

    cout << "main thread" << endl;
    cout << thread::hardware_concurrency() << endl;

    if (thread1.joinable())
        thread1.join();
    
    cout << "main exiting..." << endl;
    return 0;
}
*/