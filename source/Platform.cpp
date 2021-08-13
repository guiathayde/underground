#include "Platform.h"

Platform::Platform(GraphicManager *graphicManager, sf::Vector2f size, sf::Vector2f position)
    : Obstacle(true)
{
  texture = graphicManager->GetTexture("platform");

  body.setSize(size);
  body.setOrigin(size / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Platform::~Platform()
{
}

void Platform::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Platform::OnCollision(sf::Vector2f direction)
{
}

void Platform::Update(float deltaTime, Character *character)
{
}

sf::Vector2f Platform::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}