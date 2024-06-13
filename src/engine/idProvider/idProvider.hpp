#include <cstdint>

class idProvider {
public:
    idProvider();
    ~idProvider();
    uint64_t getID();
    uint64_t peekCurrentID();
private:
    uint64_t id = 0; // Unique ID for each object. If this is 0, the object is invalid.
};