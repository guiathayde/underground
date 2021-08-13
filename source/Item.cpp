#include "Item.h"

Item::Item(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position) : Obstacle(true)
{
  isCaught = false;
  isStair = false;
  isDoor = false;

  body.setSize(size);
  body.setOrigin(size / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Item::~Item()
{
}

void Item::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Item::OnCollision(sf::Vector2f direction)
{
}

void Item::SetCaught(bool state)
{
  isCaught = state;

  // if (isStair && isCaught)
  //   body.setPosition(body.getSize().x + 10.0f, body.getSize().y + 10.0f);
}

sf::Vector2f Item::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}