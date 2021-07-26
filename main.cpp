#include <vector>
#include <list>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Enemy.h"
#include "Platform.h"
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

  sf::Texture plataformTexture;
  plataformTexture.loadFromFile("assets/background/Plataforms/teste.png");
  
  sf::Texture playerTexture;
  playerTexture.loadFromFile("assets/characters/PlayerOne/playerV2.png");
  
  sf::Texture enemyTexture;
  enemyTexture.loadFromFile("assets/characters/EnemyMelee/enemy_melee.png");
  
  
  Player player(&playerTexture, sf::Vector2u(4, 4), sf::Vector2f(-200.0,200.0), 0.30f, 200.0f, 200.0f,100,true, true);
  Enemy enemy(&enemyTexture,sf::Vector2u(6,2), sf::Vector2f(800.0,20.0), 0.3f, 100.0f, 100.0f, 3,true);
  Enemy enemy2(&enemyTexture,sf::Vector2u(6,2), sf::Vector2f(-500.0,20.0), 0.3f, 100.0f, 100.0f, 3,true);

  std::list<Enemy> enemies;
  std::list <Enemy> :: iterator it;
  
  enemies.push_back(static_cast<Enemy>(enemy));
  enemies.push_back(static_cast<Enemy>(enemy2));

  std::vector<Platform> platforms;

  platforms.push_back(Platform(&plataformTexture, sf::Vector2f(500.0f, 200.0f), sf::Vector2f(100.0f, 600.0f)));
  platforms.push_back(Platform(&plataformTexture, sf::Vector2f(100.0f, 50.0f), sf::Vector2f(500.0f, 200.0f)));
  platforms.push_back(Platform(&plataformTexture, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f)));

  float deltaTime = 0.0f;
  sf::Clock clock;
  while (window.isOpen())
  {
      
      deltaTime = clock.restart().asSeconds();
      // solution window resize and player fall
      if (deltaTime > 1.0f / 20.0f)
        deltaTime = 1.0f / 20.0f;

      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();

        if (event.type == sf::Event::Resized)
          ResizeView(window, view);
      }
      if(player.GetIsAlive()){
        player.Update(deltaTime);

        for(it = enemies.begin();it != enemies.end();it++)
          it->Update(deltaTime,player);
        
        
        sf::Vector2f direction;

        for (int i = 0; i < platforms.size(); i++)
        {
          Platform &platform = platforms[i];
          if (platform.GetCollider().CheckCollision(player.GetCollider(), direction, 1.0f))
              player.OnCollision(direction);
            
          
          for(it = enemies.begin(); it != enemies.end(); it++){
            if (platform.GetCollider().CheckCollision(it->GetCollider(), direction, 1.0f)){
              it->OnCollision(direction);
            }
          }
        }

        for (it = enemies.begin(); it != enemies.end(); it++)
        {
          if (player.GetCollider().CheckCollision(it->GetCollider(), direction, 1.0f))
            player.GetDamage();
        }

        view.setCenter(player.GetPosition());

        window.clear();
        window.setView(view);
        
        //desenha o jogador
        if(player.GetIsAlive())
          player.Draw(window);  
        
        //desenha os inimigos a partir da lista
        for(it = enemies.begin(); it != enemies.end(); ++it){
          if(it->GetIsAlive()){
            it->Draw(window);
          }
          else
            enemies.erase(it);
          } 
        for (Platform &platform : platforms)
          platform.Draw(window);

        window.display();
        
      }
      else{
        
        window.clear();
        menu.Draw(window);
        window.display();
      
    
      }
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