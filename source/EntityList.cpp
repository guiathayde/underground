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
        cout<<ListEntities[i]<<endl;
        for(j = 0; j < size ; j++){
            if(ListEntities[i]!= ListEntities[j] && !ListEntities[j]->IsPlatform() && ListEntities[i]->GetManagerCollider().CheckCollision(ListEntities[j]->GetManagerCollider(),direction,0.1f)){
                ListEntities[j]->OnCollision(direction);
                cout <<"colidiu entidade entidade" <<endl;


            }
            
        }
    }    
}


