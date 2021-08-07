#include "Game.h"

Game::Game()
{
  graphicManager = new GraphicManager();
  //printf("ponteiro em CONSTRUTORA GAME: %p\n", graphicManager);
  mainMenu = new MainMenu(graphicManager->GetWindow()->getSize().x, graphicManager->GetWindow()->getSize().y);
  pauseMenu = new PauseMenu(graphicManager->GetWindow()->getSize().x, graphicManager->GetWindow()->getSize().y);
}

Game::~Game()
{
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
        //cout <<"resized"<<endl;
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
          int numberAction = mainMenu->SelectItem(event);
          //cout << numberAction << endl;
          if (numberAction == 1)
          {
            LevelSewer *levelsewer = new LevelSewer(graphicManager);
            levelsewer->Initialize();
            graphicManager->SetPlayerOne(levelsewer->GetPlayer());
            graphicManager->SetCurrentLevel(levelsewer);
            mainMenu->SetPlaying(true);
            cout << "Criou level" << endl;
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
        //cout <<mainMenu->GetPlaying()<<endl;

        if (pauseMenu->GetPause())
        {
          //cout <<"Não era para entrar aqui"<<endl;
          pauseMenu->SelectItem(event, *mainMenu, graphicManager->GetCurrentLevel());
        }

        else if (mainMenu->GetPlaying() && !graphicManager->GetCurrentLevel()->GetPlayer()->GetIsAlive())
        {
          //cout <<"Não era para entrar aqui"<<endl;
          graphicManager->GetCurrentLevel()->ClearAll();
          delete (graphicManager->GetCurrentLevel());
          mainMenu->SetPlaying(false);
        }

        break;
      }

      default:
        break;
      }
    }

    graphicManager->GetWindow()->clear();

    if (pauseMenu->GetPause() && mainMenu->GetPlaying())
    {
      graphicManager->GetCurrentLevel()->Draw(*graphicManager->GetWindow());
      pauseMenu->Draw(*graphicManager->GetWindow(), *graphicManager->GetView());
    }
    else if (mainMenu->GetPlaying())
    {
      graphicManager->GetCurrentLevel()->Update(deltaTime);
      graphicManager->GetCurrentLevel()->CheckCollison();
      graphicManager->SetViewCenter();
      graphicManager->GetCurrentLevel()->Draw(*graphicManager->GetWindow());
    }
    else if (!mainMenu->GetPlaying())
    {
      graphicManager->GetView()->setCenter(mainMenu->GetCenterPosition());
      mainMenu->Draw(*graphicManager->GetWindow());
    }

    graphicManager->GetWindow()->setView(*graphicManager->GetView());
    graphicManager->GetWindow()->display();
  }
}