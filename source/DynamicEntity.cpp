#include "DynamicEntity.h"
#include "ColliderManager.h"

DynamicEntity::DynamicEntity(GraphicManager* graphicManager,bool isObstacle,bool isProjectile, bool isPlayer):Entity(graphicManager)
{
	//cout << "DynamicEntity"<<endl;
	this->isObstacle = isObstacle;
	this->isProjectile = isProjectile;
	this->isPlayer = isPlayer;
}

DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}
