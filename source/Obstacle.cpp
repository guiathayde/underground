#include "Obstacle.h"

Obstacle::Obstacle(bool isPlatform,bool isSpike)
: DynamicEntity(graphicManager,isPlatform,true,false)
{
    //cout << "entrou na construtora do obstacle" <<endl;
}

Obstacle::~Obstacle()
{
}
void Obstacle::Draw(sf::RenderWindow &window)
{
    window.draw(body);
}

void Obstacle::Update(float deltaTime, Character* character){
    
}