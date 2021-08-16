#include "TrapPlatform.h"

TrapPlatform::TrapPlatform(GraphicManager *graphicManager, sf::Vector2f position)
    : Platform(graphicManager, position, TRAP_PALTFORM_ID)
{
  isTrap = true;

  sf::Texture *texture = graphicManager->GetTexture("trapPlatform");

  body.setSize(static_cast<sf::Vector2f>(texture->getSize()));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

TrapPlatform::~TrapPlatform()
{
}
