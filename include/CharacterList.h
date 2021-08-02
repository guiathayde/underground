#pragma once

#include "List.h"
#include "Character.h"
#include "Platform.h"
#include "EntityList.h"

#include <list>

class CharacterList
{
private:
    
    
    List<Character> ListCharacters;

public:
    CharacterList();
    ~CharacterList();
    
    void ListAll();
    void InsertCharacter(Character* pC);
    void RemoveCharacter(Character* pR);
    void DeleteCharacters();
    void InitializeCharacters(int enemiesNum, EntityList *entities);
    void UpdateCharacter(float deltaTime);
    void DrawCharacters(sf::RenderWindow &window);
    
    void CheckCharactersCollision(std::list<Platform *> platforms);
    Character *GetPlayer();

};

