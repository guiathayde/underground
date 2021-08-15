#include "Stair.h"

Stair::Stair(GraphicManager *graphicManager, sf::Vector2f position, int number) : 
Item(graphicManager,position,STAIR_ID)
{
  this->number = number;

  isCaught = false;
  isStair = true;
  isDoor = false;

  cout << "Entrou na construtora da stair" <<endl;

  string stairTexture = "stair" + to_string(number);
  sf::Texture *texture = graphicManager->GetTexture(stairTexture);

  body.setSize(static_cast<sf::Vector2f>(texture->getSize()));
  body.setOrigin(body.getSize() / 2.0f);
  body.setTexture(texture);
  body.setPosition(position);
}

Stair::~Stair()
{
}

void Stair::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Stair::OnCollision(sf::Vector2f direction)
{
}

void Stair::SetCaught(bool state)
{
  isCaught = state;

  // if (isStair && isCaught)
  //   body.setPosition(body.getSize().x + 10.0f, body.getSize().y + 10.0f);
}

sf::Vector2f Stair::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}