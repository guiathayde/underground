#include "DynamicEntityList.h"

DynamicEntityList::DynamicEntityList()
{
}

DynamicEntityList::~DynamicEntityList()
{
}

void DynamicEntityList::InsertDynamicEntity(DynamicEntity *pE)
{
	if (pE)
		ListEntities.Insert(pE);

}

void DynamicEntityList::RemoveDynamicEntity(DynamicEntity *pR)
{
	ListEntities.RemoveInfo(pR);
}

void DynamicEntityList::DrawEntities(sf::RenderWindow &window){
	for(int i = 0; i < ListEntities.GetSize();i++){
		ListEntities[i]->Draw(window);
	}
}