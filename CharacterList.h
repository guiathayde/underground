#pragma once

#include "List.h"
#include "Character.h"
#include "Platform.h"
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
    void InitializeCharacters(int enemiesNum);
    void UpdateCharacter(float deltaTime);
    void DrawCharaceters(sf::RenderWindow &window);
    
    void CheckCharactersCollision(std::list<Platform*> platforms);
    Character *GetPlayer();

};

