#include "Item.h"

Item::Item(GraphicManager *graphicManager, sf::Vector2f position, int id) : DynamicEntity(graphicManager, false, false, false, true)
{
  this->id = id;
}

Item::~Item()
{
}

void Item::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Item::Update(float deltaTime, Character *character)
{
}

void Item::OnCollision(sf::Vector2f direction)
{
}

sf::Vector2f Item::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}