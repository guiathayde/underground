#include <vector>
#include <list>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Level.h"
#include "Menu.h"

using std::cout;
using std::endl;

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
  sf::View view(sf::Vector2f(100.0f, 100.0f), sf::Vector2f(1280.0f, 720.0f));

  Menu menu(window.getSize().x, window.getSize().y);

  sf::Texture background;
  Level level(1, background);
  level.Initialize(2);

  float deltaTime = 0.0f;
  sf::Clock clock;

  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();
    // solution when resizing the window and the player falls
    if (deltaTime > 1.0f / 20.0f)
      deltaTime = 1.0f / 20.0f;

    sf::Event event;
    while (window.pollEvent(event))
    {
      switch (event.type)
      {
      case sf::Event::Closed:
        window.close();
        break;

      case sf::Event::Resized:
        ResizeView(window, view);
        break;

      case sf::Event::KeyReleased:
        if (event.key.code == sf::Keyboard::Escape && menu.GetPause())
          menu.SetPause(false);
        else if (event.key.code == sf::Keyboard::Escape)
          menu.SetPause(true);

        menu.SelectItem(event, window);
        break;

      default:
        break;
      }
    }

    level.Update(deltaTime);
    level.CheckCollison();

    window.clear();

    if (menu.GetPause())
    {
      view.setCenter(menu.GetCenterPosition());
      menu.Draw(window);
    }
    else
    {
      view.setCenter(level.GetPlayer().GetPosition());
      level.Draw(window);
    }

    window.setView(view);
    window.display();
  }
  return 0;
}