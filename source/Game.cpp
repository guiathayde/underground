#include "stdfx.h"
#include "Game.h"
#include "LevelSewer.h"
#include "LevelSubway.h"
#include "LevelOverground.h"

Game::Game()
{
  graphicManager = new GraphicManager();
  mainMenu = new MainMenu(graphicManager);
  pauseMenu = new PauseMenu(graphicManager);
  chapters = new Chapters(graphicManager);
  cout << "saiu da contrutora do game"<<endl;
}

Game::~Game()
{
  delete (graphicManager);
  delete (mainMenu);
  delete (pauseMenu);
  delete (chapters);
  delete (level);
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
        else if (chapters->GetChapters())
        {
          int numberAction = chapters->SelectItem(event, NULL);
          if (numberAction == 0)
          {
            chapters->SetChapters(false);
          }
          else if (numberAction == 1)
          {
            cout << "Inicializou aqui" <<endl;
            LevelSewer *levelSewer = new LevelSewer(graphicManager, colliderManager);
            levelSewer->Initialize();
            level = levelSewer;
            mainMenu->SetPlaying(true);
            chapters->SetChapters(false);
            cout << mainMenu->GetPlaying() << chapters->GetChapters() << endl;
          }
          else if (numberAction == 2)
          {
            LevelSubway *levelSubway = new LevelSubway(graphicManager, colliderManager);
            levelSubway->Initialize();
            level = levelSubway;
            mainMenu->SetPlaying(true);
            chapters->SetChapters(false);
            cout << mainMenu->GetPlaying() << chapters->GetChapters() << endl;
          }
          else if (numberAction == 3)
          {
            LevelOverground *levelOverground = new LevelOverground(graphicManager, colliderManager);
            levelOverground->Initialize();
            level = levelOverground;
            mainMenu->SetPlaying(true);
            chapters->SetChapters(false);
            cout << mainMenu->GetPlaying() << chapters->GetChapters() << endl;
          }
        }
        else if (!mainMenu->GetPlaying())
        {
          int numberAction = mainMenu->SelectItem(event, NULL);
          if (numberAction == 1)
          {
            cout << "Incializou o level"<<endl;
            LevelSewer *levelsewer = new LevelSewer(graphicManager, colliderManager);
            levelsewer->Initialize();
            mainMenu->SetPlaying(true);
            level = levelsewer;
          }
          else if (numberAction == 2)
          {
            chapters->SetChapters(true);
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

        if (pauseMenu->GetPause() && mainMenu->GetPlaying())
        {
          int numberAction = pauseMenu->SelectItem(event, level);
          if (numberAction == 0)
            pauseMenu->SetPause(false);
          else if (numberAction == 1)
          {
            level->ClearAll();
            mainMenu->SetPlaying(false);
            pauseMenu->SetPause(false);
          }
        }

        break;
      }

      default:
        break;
      }
    }
    if (graphicManager)
    {
      graphicManager->GetWindow()->clear();

      if (pauseMenu->GetPause() && mainMenu->GetPlaying())
      {
        level->Draw(*graphicManager->GetWindow());
        pauseMenu->Draw(graphicManager->GetWindow(), graphicManager->GetView());
      }
      else if (mainMenu->GetPlaying())
      {
        level->CheckCollison();
        level->Update(deltaTime);
        level->Draw(*graphicManager->GetWindow());
        level->SetViewCenter();
      }
      else if (!mainMenu->GetPlaying() && chapters->GetChapters())
      {
        graphicManager->GetView()->setCenter(chapters->GetCenterPosition());
        chapters->Draw(graphicManager->GetWindow(), graphicManager->GetView());
      }
      else if (!mainMenu->GetPlaying() && !chapters->GetChapters())
      {
        graphicManager->GetView()->setCenter(mainMenu->GetCenterPosition());
        mainMenu->Draw(graphicManager->GetWindow(), NULL);
      }

      graphicManager->GetWindow()->setView(*graphicManager->GetView());
      graphicManager->GetWindow()->display();
    }
  }
}