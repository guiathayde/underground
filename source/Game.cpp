#include "stdfx.h"
#include "Game.h"

Game::Game()
{
  graphicManager = new GraphicManager();
  mainMenu = new MainMenu(graphicManager->GetWindow()->getSize().x, graphicManager->GetWindow()->getSize().y);
  pauseMenu = new PauseMenu(graphicManager->GetWindow()->getSize().x, graphicManager->GetWindow()->getSize().y);
}

Game::~Game()
{
  delete (graphicManager);
  delete (mainMenu);
  delete (pauseMenu);
  delete(level);
}

void Game::Execute()
{
  float deltaTime = 0.0f;
  sf::Clock clock;

  while (graphicManager->WindowisOpen())
  {

    deltaTime = clock.restart().asSeconds();
    // solution when resizing the window and the player falls
    if (deltaTime > 1.0f / 20.0f)
      deltaTime = 1.0f / 20.0f;

    sf::Event event;
    while (graphicManager->GetWindow()->pollEvent(event))
    {
      switch (event.type)
      {

      case sf::Event::Closed:
        graphicManager->GetWindow()->close();
        break;

      case sf::Event::Resized:
        graphicManager->ResizeView();
        break;

      case sf::Event::KeyPressed:
      {
        if (event.key.code == sf::Keyboard::Escape && pauseMenu->GetPause())
          pauseMenu->SetPause(false);
        else if (event.key.code == sf::Keyboard::Escape)
          pauseMenu->SetPause(true);
        else if (!mainMenu->GetPlaying())
        {
          int numberAction = mainMenu->SelectItem(event, NULL);
          if (numberAction == 1)
          {
            LevelSewer *levelsewer = new LevelSewer(graphicManager, colliderManager);
            levelsewer->Initialize();
            graphicManager->SetPlayerOne(levelsewer->GetPlayer());
            graphicManager->SetCurrentLevel(levelsewer);
            mainMenu->SetPlaying(true);

            level = levelsewer;
          }

          else if (numberAction == 2)
          {
            // chapters
          }
          else if (numberAction == 3)
          {
            // ranking
          }
          else if (numberAction == 4)
          {
            graphicManager->GetWindow()->close();
          }
        }

        if (pauseMenu->GetPause())
        {
          int numberAction = pauseMenu->SelectItem(event, level);
          if (numberAction == 0)
            pauseMenu->SetPause(false);
          else if (numberAction == 1)
          {
            level->ClearAll();
            mainMenu->SetPlaying(false);
          }
        }

        break;
      }

      default:
        break;
      }
    }
    if (graphicManager)
      graphicManager->GetWindow()->clear();

    if (pauseMenu->GetPause() && mainMenu->GetPlaying())
    {
      graphicManager->GetCurrentLevel()->Draw(*graphicManager->GetWindow());
      pauseMenu->Draw(graphicManager->GetWindow(), graphicManager->GetView());
    }
    else if (mainMenu->GetPlaying())
    {
      level->CheckCollison();
      level->Update(deltaTime);
      level->Draw(*graphicManager->GetWindow());
      graphicManager->SetViewCenter();
    }
    else if (!mainMenu->GetPlaying() && graphicManager)
    {
      graphicManager->GetView()->setCenter(mainMenu->GetCenterPosition());
      mainMenu->Draw(graphicManager->GetWindow(), NULL);
    }
    if (graphicManager)
    {
      graphicManager->GetWindow()->setView(*graphicManager->GetView());
      graphicManager->GetWindow()->display();
    }
  }
}