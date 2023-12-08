#include <raylib.h>

class Entity
{
public:
  Entity();
  ~Entity();

  virtual void update(float dt);
  virtual void draw();

  Transform transform;
};