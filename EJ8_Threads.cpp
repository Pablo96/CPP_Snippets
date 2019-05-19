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

    // Basically wait for thread to finish
    if(test.thPtr->joinable())
        test.thPtr->join();

    cout << "main exited..." << endl << endl;
    return 0;
}
/*
int main()
{

    thread thread1(func1);

    cout << "main thread" << endl;

    // print A hint on the number of hardware thread contexts.
    cout << thread::hardware_concurrency() << endl;

    // A thread is joinable:
    // if it was default-constructed.
    // if it has been moved from (either constructing another thread object, or assigning to it).
    // if either of its members join or detach has been called.
    if (thread1.joinable())
        thread1.join();
    
    cout << "main exiting..." << endl;
    return 0;
}
*/