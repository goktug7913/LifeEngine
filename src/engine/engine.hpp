#include <cstdint>
#include "simObj/simObj.hpp"

struct engineConfig {
    uint64_t ticksPerSecond = 10;
};

class engine {
public:
    engine();
    ~engine();
    void run();
    void stop();
    void setConfig(engineConfig config);
    engineConfig getConfig();

    simObj spawnObj();
    
private:
    bool running = false;
    engineConfig config;

    void tick();
};