#include "WallPlatform.h"

WallPlatform::WallPlatform(GraphicManager *graphicManager, sf::Vector2f position)
: Platform(graphicManager,position)
{
  sf::Texture *texture = graphicManager->GetTexture("wallPlatform");

  body.setSize(static_cast<sf::Vector2f>(texture->getSize()));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

WallPlatform::~WallPlatform()
{
}

void WallPlatform::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void WallPlatform::OnCollision(sf::Vector2f direction)
{
}

void WallPlatform::Update(float deltaTime, Character *character)
{
}

sf::Vector2f WallPlatform::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}