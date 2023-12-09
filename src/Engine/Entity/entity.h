#include <raylib.h>
#include <vector>
#include "Engine/Entity/Component/component.h"

class Entity
{
public:
  Entity();
  ~Entity();

  virtual void update(float dt);
  virtual void draw();

  template <typename T>
  T *addComponent();

  Transform transform;

private:
  std::vector<Component *> components;
};
