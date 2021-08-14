#include "SaveManager.h"
#include "Level.h"
#include "Ranking.h"
#include "Enemy.h"

SaveManager::SaveManager(Level *level, Ranking *ranking)
{
  currentLevel = level;
  currentRanking = ranking;
}

SaveManager::~SaveManager()
{
  delete currentLevel;
}

void SaveManager::SaveLevel()
{
  string filePath = "data/saves/" + currentLevel->GetNameLevel() + ".txt";
  ofstream Writer(currentLevel->GetNameLevel(), ios::out);

  if (!Writer)
    cerr << "File cannot be opened" << endl;

  list<Character *>::iterator itCharacter;
  for (itCharacter = currentLevel->GetListCharacters()->begin(); itCharacter != currentLevel->GetListCharacters()->end(); itCharacter++)
  {
    Writer << (*itCharacter)->GetIsPlayer() << " "
           << (*itCharacter)->GetPosition().x << " "
           << (*itCharacter)->GetPosition().y << endl;
  }

  Writer.close();
}

void SaveManager::ReadLevel()
{
  string filePath = "data/saves/" + currentLevel->GetNameLevel() + ".txt";
  ifstream Reader(filePath, ios::in);

  if (!Reader)
    cerr << "File cannot be opened" << endl;

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