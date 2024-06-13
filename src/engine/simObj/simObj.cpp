#include "simObj.hpp"

simObj::simObj(idProvider& provider) : id(provider.getID()) {}

simObj::~simObj() {}

uint64_t simObj::getID() const {
    return id;
}