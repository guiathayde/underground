#include <vector>
#include <list>
#include <iostream>
#include "Level.h"
#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Platform.h"
//#include "Menu.h"

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
  sf::Texture backGround;
  //Menu menu(window.getSize().x, window.getSize().y);

  Level level(1, backGround);

  float deltaTime = 0.0f;
  sf::Clock clock;

  level.Initialize(4);
  while (window.isOpen())
  {
    deltaTime = clock.restart().asSeconds();
    // solution window resize and player fall
    if (deltaTime > 1.0f / 20.0f)
      deltaTime = 1.0f / 20.0f;
    //cout <<"delta time" <<deltaTime <<endl;
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();

      if (event.type == sf::Event::Resized)
        ResizeView(window, view);
    }


    level.Update(deltaTime);
    //cout <<level.GetPlayer()->GetPosition().x<<level.GetPlayer()->GetPosition().y<<endl;
    level.CheckCollison();
    view.setCenter(level.GetPlayer()->GetPosition());
    
    window.clear();
    window.setView(view);

    level.Draw(window);
    window.display();
  }
  return 0;
}