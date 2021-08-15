#include "SaveManager.h"
#include "Level.h"
#include "Ranking.h"
#include "Enemy.h"
#include "DynamicEntity.h"
#include "ChildPlayerOne.h"
#include "ChildPlayerTwo.h"
#include "HollowHatEnemy.h"
#include "TrashMonster.h"
#include  "WelderEnemy.h"
#include "GraphicManager.h"


SaveManager::SaveManager(GraphicManager *graphicManager, Ranking *ranking)
{
  entities = new DynamicEntityList();
  currentGraphicManager = graphicManager;
  currentLevel = NULL;
  currentRanking = ranking;
}

SaveManager::~SaveManager()
{
  delete currentLevel;
}

void SaveManager::SaveLevel()
{
  ofstream Writer("data/saves/level.txt", ios::out);

  if (!Writer)
    cerr << "File cannot be opened" << endl;

  cout << currentLevel <<endl;
  Writer << currentLevel->GetNameLevel() << endl;
  
  list<Character *>::iterator itCharacter;
  cout << "Lista character" << endl;
  for (itCharacter = currentLevel->GetListCharacters()->begin(); itCharacter != currentLevel->GetListCharacters()->end(); itCharacter++)
  {
    Writer << (*itCharacter)->GetId() << " "
           << (*itCharacter)->GetPosition().x << " "
           << (*itCharacter)->GetPosition().y << " "
           << (*itCharacter)->GetHearts() << endl;
  }

  Writer.close();
}

void SaveManager::ReadLevel()
{
  ifstream Reader("data/saves/level.txt", ios::in);

  if (Reader)
  {
    Reader >> nameLevel;

    while (!Reader.eof())
    {
      ChildPlayerOne *playerOne;
      ChildPlayerTwo *playerTwo;
      HollowHatEnemy *hollowHat;
      TrashMonster *trashMonster;
      WelderEnemy *welder;

      int id, hearts;
      float x, y;

      Reader >> id >> x >> y >> hearts;

      switch (id)
      {
      case 1:
        playerOne = new ChildPlayerOne(currentGraphicManager, sf::Vector2f(x, y));
        entities->InsertDynamicEntity(playerOne);
        characters.push_back(playerOne);
        break;

      case 2:
        playerTwo = new ChildPlayerTwo(currentGraphicManager, sf::Vector2f(x, y));
        entities->InsertDynamicEntity(playerTwo);
        characters.push_back(playerTwo);
        break;

      case 3:
        hollowHat = new HollowHatEnemy(currentGraphicManager, sf::Vector2f(x, y));
        entities->InsertDynamicEntity(hollowHat);
        characters.push_back(hollowHat);
        break;

      case 4:
        trashMonster = new TrashMonster(currentGraphicManager, sf::Vector2f(x, y));
        entities->InsertDynamicEntity(trashMonster);
        characters.push_back(trashMonster);
        break;

      case 5:
        welder = new WelderEnemy(currentGraphicManager, sf::Vector2f(x, y), entities);
        entities->InsertDynamicEntity(welder);
        break;
      
      default:
        break;
      }
    }
  }
  else
  {
    cerr << "File cannot be opened" << endl;
  }

  Reader.close();
}

void SaveManager::SaveScore()
{
  ofstream Writer("data/saves/ranking.txt", ios::out);

  if (!Writer)
    cerr << "File ranking.txt cannot be opened" << endl;

  map<string, int>::iterator itRank;
  for (itRank = currentRanking->GetRank()->begin(); itRank != currentRanking->GetRank()->end(); itRank++)
  {
    Writer << itRank->first << " "
           << itRank->second << " "
           << endl;
  }

  Writer.close();
}

void SaveManager::ReadRanking()
{
  ifstream Reader("data/saves/ranking.txt", ios::in);

  if (Reader)
  {
    while (!Reader.eof())
    {
      string name;
      int score;

      Reader >> name >> score;

      if (!name.empty() && score)
        currentRanking->SetRank(name, score);
    }

    Reader.close();
  }
  else
  {
    cerr << "File ranking.txt cannot be opened" << endl;
    Reader.close();
  }
}