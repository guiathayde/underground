#pragma once

#include "stdfx.h"
#include "List.h"
#include "DynamicEntity.h"

class DynamicEntityList
{
private:
	List<DynamicEntity *> ListEntities;

public:
	DynamicEntityList();
	~DynamicEntityList();

	void InsertDynamicEntity(DynamicEntity *pC);
	void RemoveDynamicEntity(DynamicEntity *pR);
	void DeleteEntities() { ListEntities.ClearAll(); }

	List<DynamicEntity *> *GetList() { return &ListEntities; }
};
