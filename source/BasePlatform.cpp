#include "BasePlatform.h"

BasePlatform::BasePlatform(GraphicManager *graphicManager, sf::Vector2f size, sf::Vector2f position)
    : Platform(graphicManager, position, BASE_PLATFORM_ID)
{
  isTrap = false;

  sf::Texture *texture = graphicManager->GetTexture("basePlataformTexture");

  body.setSize(size);
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

BasePlatform::~BasePlatform()
{
}
