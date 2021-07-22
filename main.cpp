#include <SFML/Graphics.hpp>
#include "Player.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1280, 720), "Underground");

  sf::Texture playerTexture;
  playerTexture.loadFromFile("assets/personagens/PlayerOne/player.png");

  Player player(&playerTexture, sf::Vector2u(4, 2), 0.3f, 100.0f);

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

    window.clear();
    player.Draw(window);
    window.display();
  }

  return 0;
}
