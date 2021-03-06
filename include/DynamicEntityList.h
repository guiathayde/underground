#pragma once

#include "stdfx.h"
#include "List.h"
#include "DynamicEntity.h"
#include "Character.h"

class DynamicEntityList
{
private:
	
	List<DynamicEntity> ListEntities;

public:
	DynamicEntityList();
	~DynamicEntityList();

	void InsertDynamicEntity(DynamicEntity *pC);
	void RemoveDynamicEntity(DynamicEntity *pR);
	void DeleteEntities() { ListEntities.ClearAll(); }

	void CheckEntitiesCollision();
	void DrawEntities(sf::RenderWindow &window);
	void Update(float deltaTime, Character* character);
	bool GetIsObstacle(int x) { return ListEntities[x]->GetIsObstacle(); }

	DynamicEntity *operator[](int x) { return ListEntities[x]; }

	int GetSize() { return ListEntities.GetSize(); }
	DynamicEntityList *GetList() { return this; }
};
