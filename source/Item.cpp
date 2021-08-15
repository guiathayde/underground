#include "Item.h"

Item::Item(GraphicManager *graphicManager, sf::Vector2f position, int id) : DynamicEntity(graphicManager,false,false,false,true)
{
  cout << "Entrou na construtora da stair" <<endl;

  
  this->id = id;

  isCaught = false;
  isStair = false;
  isDoor = false;

}

Item::~Item()
{
}

void Item::Draw(sf::RenderWindow &window)
{
  window.draw(body);
}

void Item::Update(float deltaTime,Character *character){

  //cout << GetPosition().x <<endl;
  //cout << GetPosition().y <<endl;

}


void Item::OnCollision(sf::Vector2f direction)
{
}

void Item::SetCaught(bool state)
{
  isCaught = state;

  // if (isStair && isCaught)
  //   body.setPosition(body.getSize().x + 10.0f, body.getSize().y + 10.0f);
}

sf::Vector2f Item::GetHalfSize()
{
  sf::Vector2f halfSize;
  halfSize.x = body.getSize().x / 2.0f;
  halfSize.y = body.getSize().y / 2.0f;

  return halfSize;
}