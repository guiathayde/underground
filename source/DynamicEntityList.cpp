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
		if(ListEntities[i])
			ListEntities[i]->Draw(window);
	}
}

void DynamicEntityList::Update(float deltaTime, Character* character){
	
	for(int i = 0; i < ListEntities.GetSize();i++){
		if(ListEntities[i])
			ListEntities[i]->Update(deltaTime, character);
	}

}