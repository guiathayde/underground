#include "Platform.h"

Platform::Platform(sf::Texture *texture, sf::Vector2f size, sf::Vector2f position)
:Obstacle(true)
{
  body.setSize(size);
  body.setOrigin(size / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Platform::~Platform()
{}

void Platform::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Platform::OnCollision(sf::Vector2f direction){
}
