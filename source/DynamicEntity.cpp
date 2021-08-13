#include "DynamicEntity.h"
#include "ColliderManager.h"

DynamicEntity::DynamicEntity(GraphicManager* graphicManager,bool isObstacle):Entity(graphicManager)
{
	//cout << "DynamicEntity"<<endl;
	this->isObstacle = isObstacle;
}

DynamicEntity::~DynamicEntity()
{
}

void DynamicEntity::Draw(sf::RenderWindow &window)
{
	window.draw(body);
}
