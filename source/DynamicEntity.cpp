#include "DynamicEntity.h"
#include "ColliderManager.h"

DynamicEntity::DynamicEntity(GraphicManager *graphicManager, bool isObstacle, bool isProjectile, bool isPlayer,bool isEnemy, bool isItem) : Entity(graphicManager)
{
	this->isEnemy = isEnemy;
	this->isObstacle = isObstacle;
	this->isProjectile = isProjectile;
	this->isPlayer = isPlayer;
	this->isItem = isItem;
}

DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}
