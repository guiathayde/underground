#include "Spike.h"
Spike::Spike(GraphicManager *graphicManager, sf::Vector2f size, sf::Vector2f position)
    : Obstacle(false,true)
{
  texture = graphicManager->GetTexture("spikes");

  body.setSize(size);
  body.setOrigin(size / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Spike::~Spike()
{
}

void Spike::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Spike::OnCollision(sf::Vector2f direction)
{
}

void Spike::Update(float deltaTime, Character *character)
{
}

sf::Vector2f Spike::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}