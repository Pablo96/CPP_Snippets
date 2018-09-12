#include <iostream>

void callback0();
void callback1();
void callback3(int id);

int main() {
    std::cout << "Callbacks testing" << std::endl;

    void (*callbacks[2])();
    void (*argCallbacks[2])(int);

    callbacks[0] = &callback0;
    callbacks[1] = &callback1;

    argCallbacks[0] = &callback3;
    argCallbacks[1] = &callback3;

    for (auto &callback : callbacks) {
        callback();
    }

    int i = 0;
    for (auto &callback : argCallbacks) {
        callback(i++);
    }

    return 0;
}

void callback0() {
    std::cout << "Callback 0 called!" << std::endl;
}

void callback1() {
    std::cout << "Callback 1 called!" << std::endl;
}

void callback3(int id) {
    std::cout << "Callback id: " << id << " called!" << std::endl;
}