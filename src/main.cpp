#include "Engine/engine.h"

#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#endif

int main(int argc, const char **argv) {
  Engine engine;

  #ifdef __EMSCRIPTEN__
  // For WASM we give a pointer to the run function, a delay of 0, and a flag of 1 to tell it to run the main loop repeatedly.
  emscripten_set_main_loop(&engine.run, 0, 1);
  #else

  engine.run();

  #endif
  return 0;
}
