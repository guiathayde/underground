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
	List<Character>::Element<Character> *tmp;
	tmp = ListCharacters.GetFirstList();
	while (tmp != NULL)
	{
		if (tmp->GetInfo()->GetIsPlayer())
			return tmp->GetInfo();
		tmp = ListCharacters.GetNextList(tmp);
	}
	cout << "Player not found" << endl;
	return NULL;
}

void CharacterList::RemoveCharacter(Character *pR)
{
	ListCharacters.RemoveInfo(pR);
}

void CharacterList::InitializeCharacters(int enemiesNum)
{
	static sf::Texture enemyTexture;
	static sf::Texture playerTexture;

	if (!enemyTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png"))
		printf("Error loading enemy texture\n");
	if (!playerTexture.loadFromFile("assets/characters/PlayerOne/playerV2.png"))
		printf("Error loading player texture\n");

	Player *p = NULL;
	p = new Player(&playerTexture, sf::Vector2u(4, 4), sf::Vector2f(0.0f, 200.0f), 0.30f, 200.0f, 200.0f, 300, true, true, true);
	ListCharacters.Insert(p);

	for (int i = 0; i < enemiesNum; i++)
	{
		Enemy *aux = NULL;
		aux = new Enemy(&enemyTexture, sf::Vector2u(6, 2), sf::Vector2f(i * 100.0f, 200.0f), 0.3f, 100.0f, 100.0f, 3, true, false);
		ListCharacters.Insert(aux);
	}
}

void CharacterList::UpdateCharacter(float deltaTime)
{
	List<Character>::Element<Character> *tmp;
	Character *p = GetPlayer();

	tmp = ListCharacters.GetFirstList();

	while (tmp != NULL)
	{
		tmp->GetInfo()->Update(deltaTime, p);
		tmp = ListCharacters.GetNextList(tmp);
	}
}

void CharacterList::DrawCharacters(sf::RenderWindow &window)
{
	List<Character>::Element<Character> *tmp;
	tmp = ListCharacters.GetFirstList();
	while (tmp != NULL)
	{
		tmp->GetInfo()->Draw(window);
		tmp = ListCharacters.GetNextList(tmp);
	}
}

void CharacterList::CheckCharactersCollision(std::list<Platform *> platforms)
{
	sf::Vector2f direction;
	std::list<Platform *>::iterator itPlatform;
	int i, j;
	int size = ListCharacters.GetSize();

	for (itPlatform = platforms.begin(); itPlatform != platforms.end(); itPlatform++)
		for (i = 0; i < ListCharacters.GetSize(); i++)
			if ((*itPlatform)->GetCollider().CheckCollision(ListCharacters[i]->GetCollider(), direction, 1.0f))
				ListCharacters[i]->OnCollision(direction);

	for (i = 0; i < size; i++)
		for (j = i + 1; j < size; j++)
			if (ListCharacters[i]->GetCollider().CheckCollision(ListCharacters[j]->GetCollider(), direction, 1.0f))
				ListCharacters[j]->OnCollision(direction);
}