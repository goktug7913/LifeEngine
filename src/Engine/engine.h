class Engine {
public:
  Engine();
  Engine(Engine &&) = default;
  Engine(const Engine &) = default;
  Engine &operator=(Engine &&) = default;
  Engine &operator=(const Engine &) = default;
  ~Engine();
};
