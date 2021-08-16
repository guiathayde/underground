#include "AirPlatform.h"

AirPlatform::AirPlatform(GraphicManager *graphicManager, sf::Vector2f position)
    : Platform(graphicManager, position, AIR_PLATFORM_ID)
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
