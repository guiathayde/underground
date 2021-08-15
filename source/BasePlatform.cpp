#include "BasePlatform.h"

BasePlatform::BasePlatform(GraphicManager *graphicManager, sf::Vector2f size, sf::Vector2f position)
: Platform(graphicManager,position, BASE_PLATFORM_ID)
{
  sf::Texture *texture = graphicManager->GetTexture("basePlataformTexture");

  body.setSize(size);
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

BasePlatform::~BasePlatform()
{
}

void BasePlatform::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void BasePlatform::OnCollision(sf::Vector2f direction)
{
}

void BasePlatform::Update(float deltaTime, Character *character)
{
}

sf::Vector2f BasePlatform::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}