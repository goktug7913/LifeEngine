#pragma once
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
 
  template <typename T, typename... Args>
  T* addComponent(Args&&... args);

  template <typename T>
  T* getComponent()
  {
    for (auto &component : this->components)
    {
      T* castedComponent = dynamic_cast<T*>(component);
      if (castedComponent != nullptr)
      {
        return castedComponent;
      }
    }
    return nullptr;
  }

  Transform* transform;

private:
  std::vector<Component*> components;
};
