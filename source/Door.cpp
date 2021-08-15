#include "Door.h"

Door::Door(GraphicManager *graphicManager, sf::Vector2f position) : Item(graphicManager,position,DOOR_ID)
{
  isCaught = false;
  isStair = false;
  isDoor = false;

  texture = graphicManager->GetTexture("door");

  body.setSize(static_cast<sf::Vector2f>(texture->getSize()));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Door::~Door()
{
}

void Door::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Door::OnCollision(sf::Vector2f direction)
{
}

void Door::SetCaught(bool state)
{
  isCaught = state;

  // if (isStair && isCaught)
  //   body.setPosition(body.getSize().x + 10.0f, body.getSize().y + 10.0f);
}

sf::Vector2f Door::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}