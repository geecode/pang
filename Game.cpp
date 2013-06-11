// member function definitions for class Game

#include "stdafx.h"
#include "Game.h"
#include "SplashScreen.h"
#include "MainMenu.h"

void Game::Start()
{
    if ( _gameState != Unititialized )
        return;
    _mainWindow.create( sf::VideoMode( 1024, 768, 32 ), "Pang!" );
    _gameState = Game::ShowingSplash;

    while ( !Game::isExiting() )
    {
        GameLoop();
    }

    _mainWindow.close();
}

bool Game::isExiting()
{
    if ( _gameState == Game::Exiting )
        return true;
    else
        return false;
}

void Game::GameLoop()
{
    sf::Event currentEvent;
	while ( _mainWindow.pollEvent( currentEvent ) )
    {
        switch( _gameState )
        {
		case Game::ShowingMenu:
			ShowMenu();
			break;
		case Game::ShowingSplash:
			ShowSplashScreen();
			break;
        case Game::Playing:
            {
                _mainWindow.clear( sf::Color( 255, 0, 0 ) );
                _mainWindow.display();

                if ( currentEvent.type == sf::Event::Closed )
                    _gameState = Game::Exiting; 

				if ( currentEvent.type == sf::Event::KeyPressed ) {
					if ( sf::Keyboard::isKeyPressed( sf::Keyboard::Escape ) )
						ShowMenu();
				}

                break;
            }
        }
    }
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show( _mainWindow );
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show( _mainWindow );

	switch( result )
	{
	case MainMenu::Exit:
		_gameState = Game::Exiting;
		break;
	case MainMenu::Play:
		_gameState = Game::Playing;
		break;
	}
}

Game::GameState Game::_gameState = Unititialized;
//Game::GameState Game::Unititialized;
sf::RenderWindow Game::_mainWindow;


