#include "AirPlatform.h"

AirPlatform::AirPlatform(GraphicManager *graphicManager, sf::Vector2f position)
: Platform(graphicManager,position,AIR_PLATFORM_ID)
{
  sf::Texture *texture = graphicManager->GetTexture("airPlatform");

  body.setSize(static_cast<sf::Vector2f>(texture->getSize()));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

AirPlatform::~AirPlatform()
{
}

void AirPlatform::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void AirPlatform::OnCollision(sf::Vector2f direction)
{
}

void AirPlatform::Update(float deltaTime, Character *character)
{
}

sf::Vector2f AirPlatform::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}