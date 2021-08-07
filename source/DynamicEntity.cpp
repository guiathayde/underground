#include "DynamicEntity.h"
#include "ColliderManager.h"

DynamicEntity::DynamicEntity(bool isObstacle)
{
	this->isObstacle = isObstacle;
}

DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}
