#include "Entity.h"

Entity::Entity(GraphicManager* graphicManager){
    //cout <<"Construtora do entity"<<endl;
    this->graphicManager = graphicManager;
}

Entity::~Entity(){}