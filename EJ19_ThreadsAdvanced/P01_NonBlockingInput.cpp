/*
Non blocking input
*/

#include <iostream>
#include <string>
#include <thread>
#include <utility>

bool no_exit = true;


void func(int n, std::string in_string)
{
    std::thread::id id = std::this_thread::get_id();
    std::cout << id << " :: " << n << " : " << in_string << std::endl;
    
    std::cin.get();
    no_exit = false;
}

int main(int argc, char** argv)
{
    std::thread t0(func, 4, "test");
    
    t0.detach();

    while (no_exit)
    {
        std::cout << "Main\n";
    }

    return 0;
}