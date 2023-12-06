class Engine {
public:
  Engine();
  ~Engine();
  
  void run();

  void handleEvents();
  void update();
  void render();

private:
  int width;
  int height;
  int targetFps;
};
