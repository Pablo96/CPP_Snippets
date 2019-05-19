#include <iostream>
#include <ostream>
#include <string>
#include <thread>
#include <utility>

bool no_exit = true;

struct vec3
{
    float x = 0, y = 0, z = 0;
} vector;

std::ostream& operator<<(std::ostream& os, const vec3& vec)
{
    os << "(" << vec.x << ", " << vec.y << ", " << vec.z  << ")";
    return os;
}

void func()
{
    char key;
    while (no_exit)
    {
        std::cin >> key;
        switch(key)
        {
        case 'w':
            vector.y += 1;
            break;
        case 's':
            vector.y -= 1;
            break;
        default:
            no_exit = false;
        }
    }
}

int main(int argc, char** argv)
{
    std::thread t0(func);

    while (no_exit)
    {
        std::cout << vector << std::endl;
    }

    t0.join();
    return 0;
}