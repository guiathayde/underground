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
  modMenu = new ModMenu(graphicManager);
  chapters = new Chapters(graphicManager);
  ranking = new Ranking(graphicManager);
  saveManager = new SaveManager(graphicManager, ranking);
  levelNumber = 0;
}

Game::~Game()
{
  delete (graphicManager);
  delete (saveManager);
  delete (mainMenu);
  delete (chapters);

}

void Game::Execute()
{
  saveManager->ReadRanking();

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

      case sf::Event::TextEntered:
        if (level != NULL && level->GetEndLevel())
          level->SetEndLevel(event);
        break;

      case sf::Event::KeyPressed:
      {
        if (event.key.code == sf::Keyboard::Escape && pauseMenu->GetPause())
          pauseMenu->SetPause(false);
        else if (event.key.code == sf::Keyboard::Escape)
          pauseMenu->SetPause(true);
        else if (modMenu->GetModMenu())
        {
          bool isSecondPlayer = false;
          bool isChoosable = false;
          if (modMenu->SelectItem(event, level) == 1)
          {
            isSecondPlayer = true;
            isChoosable = true;
          }
          else if (modMenu->SelectItem(event, level) == 0)
          {
            isSecondPlayer = false;
            isChoosable = true;
          }

          if (isChoosable)
          {
            switch (levelNumber)
            {
            case 1:
            {
              LevelSewer *levelSewer = new LevelSewer(graphicManager, colliderManager, isSecondPlayer);
              levelSewer->Initialize();
              level = levelSewer;
              mainMenu->SetPlaying(true);
              chapters->SetChapters(false);
              modMenu->SetModMenu(false);
              break;
            }

            case 2:
            {
              LevelSubway *levelSubway = new LevelSubway(graphicManager, colliderManager, isSecondPlayer);
              levelSubway->Initialize();
              level = levelSubway;
              mainMenu->SetPlaying(true);
              chapters->SetChapters(false);
              modMenu->SetModMenu(false);
              break;
            }

            case 3:
            {
              LevelOverground *levelOverground = new LevelOverground(graphicManager, colliderManager, isSecondPlayer);
              levelOverground->Initialize();
              level = levelOverground;
              mainMenu->SetPlaying(true);
              chapters->SetChapters(false);
              modMenu->SetModMenu(false);
              break;
            }

            default:
              break;
            }
          }
        }
        else if (chapters->GetChapters())
        {
          int numberAction = chapters->SelectItem(event, NULL);
          if (numberAction == 0)
          {
            chapters->SetChapters(false);
          }
          else if (numberAction != -1)
          {
            levelNumber = numberAction;
            modMenu->SetModMenu(true);
            chapters->SetChapters(false);
          }
        }
        else if (ranking->GetRanking())
        {
          if (ranking->SelectItem(event, NULL) == 0)
            ranking->SetRanking(false);
        }
        else if (!mainMenu->GetPlaying())
        {
          int numberAction = mainMenu->SelectItem(event, NULL);
          if (numberAction == 1)
          {
            modMenu->SetModMenu(true);
            levelNumber = numberAction;
          }
          else if (numberAction == 2)
          {
            
            string nameLevel = saveManager->ReadNameLevel();
            if (nameLevel == "Sewer")
            {
              LevelSewer *levelSewer = new LevelSewer(graphicManager, colliderManager, false);
              level = levelSewer;
              saveManager->SetLevel(level);
              saveManager->ReadLevel();
              mainMenu->SetPlaying(true);
              chapters->SetChapters(false);
            }
            else if (nameLevel == "Subway")
            {
              LevelSubway *levelSubway = new LevelSubway(graphicManager, colliderManager, false);
              level = levelSubway;
              saveManager->SetLevel(level);
              saveManager->ReadLevel();

              mainMenu->SetPlaying(true);
              chapters->SetChapters(false);
            }
            else if (nameLevel == "Overground")
            {
              LevelOverground *levelOverground = new LevelOverground(graphicManager, colliderManager, false);
              level = levelOverground;
              saveManager->SetLevel(level);
              saveManager->ReadLevel();

              mainMenu->SetPlaying(true);
              chapters->SetChapters(false);
            }
          }
          else if (numberAction == 3)
          {
            chapters->SetChapters(true);
          }
          else if (numberAction == 4)
          {
            ranking->SetRanking(true);
          }
          else if (numberAction == 5)
          {
            saveManager->SaveScore();
            graphicManager->GetWindow()->close();
          }
        }
        else if (level != NULL && level->GetEndLevel())
        {
          int numberAction = level->SetContinueLevel(event, ranking);
          if (numberAction == 0)
          {
            level->ClearAll();
            mainMenu->SetPlaying(false);
          }
          else if (numberAction == 2)
          {
            bool tmp = level->GetIsCoop();
            level->ClearAll();
            LevelSubway *levelSubway = new LevelSubway(graphicManager, colliderManager, tmp);
            levelSubway->Initialize();
            level = levelSubway;
            mainMenu->SetPlaying(true);
            chapters->SetChapters(false);
          }
          else if (numberAction == 3)
          {
            bool tmp = level->GetIsCoop();
            level->ClearAll();
            LevelOverground *levelOverground = new LevelOverground(graphicManager, colliderManager, tmp);
            levelOverground->Initialize();
            level = levelOverground;
            mainMenu->SetPlaying(true);
            chapters->SetChapters(false);
          }
        }

        if (pauseMenu->GetPause() && mainMenu->GetPlaying())
        {
          int numberAction = pauseMenu->SelectItem(event, level);
          if (numberAction == 0)
            pauseMenu->SetPause(false);
          else if (numberAction == 1)
          {
            saveManager->SetLevel(level);
            saveManager->SaveLevel();
          }
          else if (numberAction == 2)
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
      else if (!mainMenu->GetPlaying() && modMenu->GetModMenu())
      {
        graphicManager->GetView()->setCenter(modMenu->GetCenterPosition());
        modMenu->Draw(graphicManager->GetWindow(), graphicManager->GetView());
      }
      else if (!mainMenu->GetPlaying() && chapters->GetChapters())
      {
        graphicManager->GetView()->setCenter(chapters->GetCenterPosition());
        chapters->Draw(graphicManager->GetWindow(), graphicManager->GetView());
      }
      else if (!mainMenu->GetPlaying() && ranking->GetRanking())
      {
        graphicManager->GetView()->setCenter(ranking->GetCenterPosition());
        ranking->Draw(graphicManager->GetWindow(), graphicManager->GetView());
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