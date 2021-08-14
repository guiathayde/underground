#include "SaveManager.h"
#include "Level.h"
#include "Enemy.h"

SaveManager::SaveManager(Level *level)
{
  currentLevel = level;
}

SaveManager::~SaveManager()
{
  delete currentLevel;
}

void SaveManager::SaveLevel(string nameLevel)
{
  string filePath = "data/saves/";
  filePath += nameLevel + ".txt";
  ofstream Writer(filePath, ios::out);

  if (!Writer)
  {
    cerr << "File cannot be opened" << endl;
    fflush(stdin);
  }

  list<Character *>::iterator itCharacter;
  for (itCharacter = currentLevel->GetListCharacters()->begin(); itCharacter != currentLevel->GetListCharacters()->end(); itCharacter++)
  {
    Writer << (*itCharacter)->GetIsPlayer() << " "
           << (*itCharacter)->GetPosition().x << " "
           << (*itCharacter)->GetPosition().y << endl;
  }

  Writer.close();
}

void SaveManager::ReadLevel(string nameLevel)
{
  string filePath = "data/saves/" + nameLevel + ".txt";
  ifstream Reader(filePath, ios::in);

  if (!Reader)
  {
    cerr << "File cannot be opened" << endl;
    fflush(stdin);
  }

  while (!Reader.eof())
  {
    Player *player;
    Enemy *enemy;

    bool isPlayer;
    float x;
    float y;

    Reader >> isPlayer >> x >> y;

    if (isPlayer)
    {
      // criar jogador e colocar na lista de characters
    }
  }

  Reader.close();
}