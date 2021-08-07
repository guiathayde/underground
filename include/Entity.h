#include "stdfx.h"

class Entity
{
private:
public:
  Entity();
  ~Entity();

  virtual void Draw(sf::RenderWindow &window) = 0;
};
