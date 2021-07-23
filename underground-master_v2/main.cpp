#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Enemy.h"
int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Underground");

  sf::Texture playerTexture;
  sf::Texture enemyMeleeTexture;
  playerTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png");
  enemyMeleeTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png");
  Player player(&playerTexture, sf::Vector2u(6, 2), 0.3f, 100.0f,50.0f);
  Enemy enemy(&enemyMeleeTexture,sf::Vector2u(6,2), 0.3f,100.0f);

  float deltaTime = 0.0f;
  sf::Clock clock;

  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    player.Update(deltaTime);
    enemy.Update(deltaTime);

    window.clear();
    player.Draw(window);
    enemy.Draw(window);
    window.display();
  }

  return 0;
}
