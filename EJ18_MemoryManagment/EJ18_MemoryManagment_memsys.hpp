#pragma once
#include "EJ18_MemoryManagment_common.hpp"
#include <memory>

class ComponentManager
{
public:
    ComponentManager() = default;
    ~ComponentManager() = default;

    void addComponent();
};
