/*

*/

#include <iostream>
#include <string>
#include <vector>
#include <thread>

class Layer
{
public:
    void OnUpdate(float in_deltaTime)
    {
        std::cout << in_deltaTime << std::endl;
    }
    void OnRender()
    {
        std::cout << "OnRender" << std::endl;
    }
};
class App
{
    std::vector<std::thread*> pool;
public:
    App();
    ~App();

    void Run();
};

int main(int argc, char** argv)
{
    App app;

    app.Run();

    return 0;
}
