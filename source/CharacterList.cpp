#include <iostream>
using namespace std;

#include "CharacterList.h"
#include "Enemy.h"
#include "Player.h"

CharacterList::CharacterList()
{
}

CharacterList::~CharacterList()
{
    ListCharacters.ClearAll();
}

void CharacterList::InsertCharacter(Character *pC)
{
    if (pC != NULL)
        ListCharacters.Insert(pC);
}

Character *CharacterList::GetPlayer()
{
    Character* player;
    player = ListCharacters.GetFirstList();
    while(player != NULL){
        if(player->GetIsPlayer()){
            cout <<"Achaou o player"<<endl;
            return player;
        }
        player = ListCharacters.GetNextList();
    }
    cout <<"Não achou o player"<<endl;
    return ListCharacters.GetFirstList();
}

void CharacterList::RemoveCharacter(Character *pR)
{
    ListCharacters.RemoveInfo(pR);
}

void CharacterList::InitializeCharacters(int enemiesNum, EntityList *entities, GraphicManager *graphicManager)
{

    //carrega as imagens
    Player *p = NULL;
    cout <<"Criou player, ponteiro textura player"<< graphicManager->GetTexture("playerOne") <<endl;
    p = new Player(graphicManager->GetTexture("playerOne"), sf::Vector2f(60.0f, 40.0f), sf::Vector2f(0.0f, 600.0f), sf::Vector2u(4, 4), 0.30f, 200.0f, 200.0f, 300, true, true, true);
    ListCharacters.Insert(p);
    entities->InsertEntity(p);
    //cout <<p->GetIsPlayer()<<endl;
    for (int i = 0; i < enemiesNum; i++)
    {
         Enemy *aux = NULL;
         aux = new Enemy(graphicManager->GetTexture("enemyMelee"), sf::Vector2f(100, 100), sf::Vector2f(i * 100.0f, 200.0f), sf::Vector2u(6, 2), 0.3f, 100.0f, 100.0f, 3, false, true);
        //cout <<"Criou characters"<<endl;
         ListCharacters.Insert(aux);
         entities->InsertEntity(aux);
    }
}

void CharacterList::UpdateCharacter(float deltaTime)
{

    Character *tmp;

    Character *p = ListCharacters.GetFirstList();

    tmp = ListCharacters.GetFirstList();

    while (tmp != NULL)
    {
        tmp->Update(deltaTime, p);
        tmp = ListCharacters.GetNextList();
    }
}

void CharacterList::DrawCharacters(sf::RenderWindow &window)
{

    Character *tmp;
    tmp = ListCharacters.GetFirstList();
    while (tmp != NULL)
    {
        tmp->Draw(window);
        tmp = ListCharacters.GetNextList();
    }
}

void CharacterList::CheckCharactersCollision(std::list<Platform *> platforms)
{

    sf::Vector2f direction;
    std::list<Platform *>::iterator itPlatform;

    int i, j;

    int size = ListCharacters.GetSize();

    for (itPlatform = platforms.begin(); itPlatform != platforms.end(); itPlatform++)
    {

        for (i = 0; i < ListCharacters.GetSize(); i++)
        {
            if ((*itPlatform)->GetCollider().CheckCollision(ListCharacters[i]->GetCollider(), direction, 0.1f))
            {
                ListCharacters[i]->OnCollision(direction);
            }
        }
    }

    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (ListCharacters[i]->GetCollider().CheckCollision(ListCharacters[j]->GetCollider(), direction, 0.1f))
                ListCharacters[j]->OnCollision(direction);
        }
    }
}
void CharacterList::DeleteCharacters()
{
    ListCharacters.ClearAll();
}