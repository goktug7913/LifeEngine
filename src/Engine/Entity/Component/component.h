class Component
{
public:
    virtual ~Component() = 0;
    virtual void update(float dt) = 0;
    virtual void draw() = 0;
};
