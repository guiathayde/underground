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
		ListEntities.Insert(&pE);
}

void DynamicEntityList::RemoveDynamicEntity(DynamicEntity *pR)
{
	ListEntities.RemoveInfo(&pR);
}