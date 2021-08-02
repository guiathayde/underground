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
    int cont = 0;

    for(i = 0; i < size; i++){
        for(j = 0; j < size ; j++){
            if(ListEntities[i]!= ListEntities[j] && !ListEntities[j]->IsPlatform() && ListEntities[i]->GetCollider().CheckCollision(ListEntities[j]->GetCollider(),direction,0.1f)){
                ListEntities[j]->OnCollision(direction);
            }
            
        }
    }  


}