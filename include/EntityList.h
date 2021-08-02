#pragma once
#include "List.h"
#include "Entity.h"
#include "Collider.h"

class EntityList
{
private:
    
    List<Entity> ListEntities;
    
    int n_entities;

public:
    
    EntityList(int n_entities, bool isPlatform);
    ~EntityList();
    
    void InsertEntity(Entity* pC);
    void RemoveEntity(Entity* pR);
    void DeleteEntitys(){

        cout <<"entou no delete "<<endl;
        ListEntities.ClearAll();
         cout <<"entou no delete "<<endl;
    }
    
    void InitializeEntitys(int enemiesNum);
    void UpdateEntity(float deltaTime);
    void DrawEntitys(sf::RenderWindow &window);
    

    void CheckEntitysCollision();

    

    List<Entity>* GetList(){return &ListEntities;}
    Entity *GetPlayer();

};

