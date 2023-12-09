#include "component.h"
#include <iostream>

Component::~Component()
{
    std::cout << "Component destroyed" << std::endl;
}