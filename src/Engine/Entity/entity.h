#pragma once
#include "Engine/Entity/Component/component.h"
#include <raylib.h>
#include <vector>

class Entity {
public:
  explicit Entity(const Transform *transform);
  virtual ~Entity();

  Transform *transform{};

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

private:
  std::vector<Component *> components;
};
