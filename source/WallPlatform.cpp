#include "WallPlatform.h"

WallPlatform::WallPlatform(GraphicManager *graphicManager, sf::Vector2f position)
    : Platform(graphicManager, position, WALL_PLATFORM_ID)
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