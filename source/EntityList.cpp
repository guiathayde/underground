#include "EntityList.h"

EntityList::EntityList(int n_entities, bool isPlatform){
}

EntityList::~EntityList(){

}

void EntityList::InsertEntity(Entity* pE){
    if(pE)
        ListEntities.Insert(pE);
    
}

void EntityList::DrawEntitys(sf::RenderWindow &window){
    int i, j;

    int size = ListEntities.GetSize();
    
    for(i = 0; i < size; i++){
        ListEntities[i]->Drawn(window);     
    }
    
}

void EntityList::CheckEntitysCollision(){

    sf::Vector2f direction;;
    
    int i, j;

    int size = ListEntities.GetSize();
    

    for(i = 0; i < size; i++){
        for(j = i+1; j < size; j++){
            if(!ListEntities[i]->IsPlatform() && ListEntities[i]->GetManagerCollider().CheckCollision(ListEntities[j]->GetManagerCollider(),direction,0.1f))
                ListEntities[j]->OnCollision(direction);

        }
    }
}
