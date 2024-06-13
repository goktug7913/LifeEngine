#include "idProvider.hpp"
#include <iostream>

idProvider::idProvider()
{
}

idProvider::~idProvider()
{
}

uint64_t idProvider::getID()
{
    id++;
    std::cout << "idProvider::getID(): " << id << std::endl;
    return id;
}

uint64_t idProvider::peekCurrentID()
{
    std::cout << "idProvider::peekCurrentID(): " << id << std::endl;
    return id;
}