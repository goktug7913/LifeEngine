#pragma once
#include "Engine/Entity/Component/component.h"
#include <raylib.h>
#include <vector>

struct Size {
  float x;
  float y;
};

enum class Sex {
  MALE,
  FEMALE,
  NA,
};

class Entity {
public:
  explicit Entity(const Transform* transform);
  virtual ~Entity();

  Transform *transform{};
  Size size{};
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

private:
  std::vector<Component *> components;
};
