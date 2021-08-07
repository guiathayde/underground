#pragma once

#include "List.h"
#include "EntityList.h"
#include "GraphicManager.h"
#include "Platform.h"

class CharacterList
{
private:
    List<Character> ListCharacters;

public:
    CharacterList();
    ~CharacterList();
 
    void InsertCharacter(Character *pC);
    void RemoveCharacter(Character *pR);
    void DeleteCharacters();
    void InitializeCharacters(int enemiesNum, EntityList *entities, GraphicManager *graphicManager);
    void UpdateCharacter(float deltaTime);
    void DrawCharacters(sf::RenderWindow &window);

    //void CheckCharactersCollision(std::list<Platform *> platforms);
    Character *GetPlayer();
};
