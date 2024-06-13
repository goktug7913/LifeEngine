#include <cstdint>
#include "engine/idProvider/idProvider.hpp"

class simObj {
    public:
        simObj(idProvider& provider);
        virtual ~simObj();
        uint64_t getID() const;
    private:
        uint64_t id = 0; // Unique ID for each object. If this is 0, the object is invalid.
        
};