#include <vector>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Platform.h"

static const float VIEW_WIDTH = 1280.0f;
static const float VIEW_HEIGHT = 720.0f;

void ResizeView(const sf::RenderWindow &window, sf::View &view)
{
  float aspectRatio = float(window.getSize().x / float(window.getSize().y));
  view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
  sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Underground");
  sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1280.0f, 720.0f));

  sf::Texture playerTexture;
  playerTexture.loadFromFile("assets/characters/PlayerOne/player.png");

  Player player(&playerTexture, sf::Vector2u(4, 2), 0.3f, 100.0f, 200.0f);

  std::vector<Platform> platforms;

  platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
  platforms.push_back(Platform(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
  platforms.push_back(Platform(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));

  float deltaTime = 0.0f;
  sf::Clock clock;

  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();
    // if had a problem with resizing the screen and the character falls
    // if (deltaTime > 1.0f / 20.0f)
    //   deltaTime = 1.0f / 20.0f;

    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::Resized)
        ResizeView(window, view);
    }

    player.Update(deltaTime);

    sf::Vector2f direction;

    for (int i = 0; i < platforms.size(); i++)
    {
      Platform &platform = platforms[i];

      if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
        player.OnCollision(direction);
    }

    view.setCenter(player.GetPosition());

    window.clear();
    window.setView(view);
    player.Draw(window);

    for (Platform &platform : platforms)
      platform.Draw(window);

    window.display();
  }

  return 0;
}

// this:
// for (int i = 0; i < platforms.size(); i++)
// {
//   Platform &platform = platforms[i];
//   platform.Draw(window);
// }
//
// is equal to this:
// for (Platform &platform : platforms)
//   platform.Draw(window);