#pragma once

#include "stdfix.h"
#include "DynamicEntity.h"

class Item : public DynamicEntity
{
private:
  int id;
  
  bool isCaught;
  bool isStair;
  bool isDoor;

public:
  Item(GraphicManager *graphciManager, sf::Vector2f position,int id);
  ~Item();

  void Update(float deltaTime,Character* character);
  
  void Draw(sf::RenderWindow &window);
  void OnCollision(sf::Vector2f direction);

  void SetCaught(bool state);
  bool GetCaught() { return isCaught; }

  void SetStair(bool state) { isStair = state; }
  bool GetStair() { return isStair; }

  void SetDoor(bool state) { isDoor = state; }
  bool GetDoor() { return isDoor; };

  virtual int GetNumber(){return 0;};

  void SetPosition(sf::Vector2f position) { body.setPosition(position); }
  sf::Vector2f GetPosition() { return body.getPosition(); }

  sf::Vector2f GetSize() { return body.getSize(); }
  sf::Vector2f GetHalfSize();

  int GetId(){return id;}
};