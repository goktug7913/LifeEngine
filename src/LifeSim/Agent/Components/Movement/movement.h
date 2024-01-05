#include "../../../../Engine/Entity/Component/component.h"
#include "../../../../Engine/Entity/entity.h"
#include "src/LifeSim/Agent/Components/Genetics/genetics.h"
#include <raylib.h>

class Movement : public Component {
public:
  explicit Movement(Entity *parent) : Component(parent) {}
  ~Movement() override;

  Vector2 target = {0, 0};
  float speed = parent->getComponent<Genetics>()->getSpeed();

  void update(float dt) override;
  void draw() override{};
  void moveTowardsTarget(Vector2 target, float dt) const;
  bool isMoving();
};
