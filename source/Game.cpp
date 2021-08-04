#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Execute()
{
  float deltaTime = 0.0f;
  sf::Clock clock;

  while (window->isOpen())
  {

    deltaTime = clock.restart().asSeconds();
    // solution when resizing the window and the player falls
    if (deltaTime > 1.0f / 20.0f)
      deltaTime = 1.0f / 20.0f;

    sf::Event event;
    while (window->pollEvent(event))
    {
      switch (event.type)
      {

      case sf::Event::Closed:
        window->close();
        break;

      case sf::Event::Resized:
        ResizeView();
        break;

      case sf::Event::KeyPressed:
      {
        if (event.key.code == sf::Keyboard::Escape && pauseMenu->GetPause())
          pauseMenu->SetPause(false);
        else if (event.key.code == sf::Keyboard::Escape)
          pauseMenu->SetPause(true);
        else if (!mainMenu->GetPlaying())
        {
          int numberAction = mainMenu->SelectItem(event);
          cout << numberAction << endl;
          if (numberAction == 1)
          {
            LevelSewer *levelsewer = new LevelSewer(view, window);
            levelsewer->Initialize(*window, &textures);
            SetPlayerOne(levelsewer->GetPlayer());
            SetCurrentLevel(levelsewer);
            mainMenu->SetPlaying(true);
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
            currentLevel->ClearAll();
            window->close();
          }
        }
        if (pauseMenu->GetPause())
          pauseMenu->SelectItem(event, *mainMenu, *currentLevel);

        break;
      }

      default:
        break;
      }
    }

    window->clear();

    if (pauseMenu->GetPause() && mainMenu->GetPlaying())
    {
      currentLevel->Draw(*window);
      pauseMenu->Draw(*window, *view);
    }
    else if (mainMenu->GetPlaying())
    {
      currentLevel->Update(deltaTime);
      currentLevel->CheckCollison();
      SetViewCenter();
      currentLevel->Draw(*window);
    }
    else if (!mainMenu->GetPlaying())
    {
      view->setCenter(mainMenu->GetCenterPosition());
      mainMenu->Draw(*window);
    }

    window->setView(*view);
    window->display();
  }
}