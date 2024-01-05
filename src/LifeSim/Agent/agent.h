#pragma once
#include "Engine/Entity/entity.h"
#include "src/Engine/Entity/Component/StateMachine/stateMachine.h"
#include "src/LifeSim/Agent/Components/Genetics/genetics.h"
#include "src/LifeSim/Agent/Components/Movement/movement.h"

enum class Sex {
  MALE,
  FEMALE,
  NA,
};

struct Size {
  float x;
  float y;
};

class Agent : public Entity {
public:
  Size size{};
  Sex sex = Sex::NA;
  Color color{};

  explicit Agent(const Transform *transform) : Entity(transform) {
    addComponent<Genetics>(this);
    addComponent<Movement>(this);
    addComponent<StateMachine>(this);

    // Randomize sex
    sex = getComponent<Genetics>()->getSex();
    size = getComponent<Genetics>()->getSize();
    color = getComponent<Genetics>()->getColor();
  };

  virtual ~Agent();

  void update(float dt) override;
  void draw() override;
};