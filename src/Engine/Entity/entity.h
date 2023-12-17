#pragma once
#include "Engine/Entity/Component/component.h"
#include <raylib.h>
#include <vector>

struct Size {
  float x = 10;
  float y = 10;
};

enum class Sex {
  MALE,
  FEMALE,
  NA,
};

class Entity {
public:
  Entity();
  ~Entity();

  Size size;
  Sex sex;

  virtual void update(float dt);
  virtual void draw();

  template <typename T, typename... Args> T *addComponent(Args &&...args);

  template <typename T> T *getComponent() {
    for (auto &component : this->components) {
      T *castedComponent = dynamic_cast<T *>(component);
      if (castedComponent != nullptr) {
        return castedComponent;
      }
    }
    return nullptr;
  }

  Transform *transform;

private:
  std::vector<Component *> components;
};
