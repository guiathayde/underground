#include "TrapPlatform.h"

TrapPlatform::TrapPlatform(GraphicManager *graphicManager, sf::Vector2f position)
: Platform(graphicManager,position,TRAP_PALTFORM_ID)
{
  cout <<"entrou na construtora do trapPlatform"<< endl;

  sf::Texture *texture = graphicManager->GetTexture("trapPlatform");

  body.setSize(static_cast<sf::Vector2f>(texture->getSize()));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);

  cout <<"saiu na construtora do trapPlatform"<< endl;

}

TrapPlatform::~TrapPlatform()
{
}

void TrapPlatform::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void TrapPlatform::OnCollision(sf::Vector2f direction)
{
}

void TrapPlatform::Update(float deltaTime, Character *character)
{
}

sf::Vector2f TrapPlatform::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}