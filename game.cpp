#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "splashscreen.h"
#include "mainmenu.h"
#include "gameobjectmanager.h"

void Game::Start(void)
{
	if(_gameState != Uninitialized)
		return;
	
	_mainWindow.create(sf::VideoMode(1024,768), "gamefromscratch.com tutorial app");

	PlayerPaddle* player1 = new PlayerPaddle();
	player1->Load("img/paddle.png");
	player1->SetPosition((1024/2)-45,700);
	
	_gameObjectManager.Add("Paddle1",player1);
	_gameState = Game::ShowingSplash;
	
	while(!IsExiting())
	{
		GameLoop();
	}
	
	_mainWindow.close();
}


bool Game::IsExiting()
{
	if(_gameState == Game::Exiting)
		return true;
	else
		return false;
}

void Game::ShowSplashScreen()
{
	SplashScreen splashScreen;
	splashScreen.Show(_mainWindow);
	_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
	MainMenu mainMenu;
	MainMenu::MenuResult result = mainMenu.Show(_mainWindow);
	switch(result)
	{
		case MainMenu::Exit:
			_gameState = Game::Exiting;
			break;
		case MainMenu::Play:
			_gameState = Game::Playing;
			break;
		case MainMenu::Nothing:
			_gameState = Game::ShowingMenu;
			break;
	}
}


void Game::GameLoop()
{
	sf::Event currentEvent;
	_mainWindow.pollEvent(currentEvent);
	
	switch(_gameState)
	{
		case Game::Uninitialized:
		{
			std::cout << "oh god how did this get here" << std::endl
				<< "i am not good with computer" << std::endl;
			exit(1);
		}
		
		case Game::Playing:
		{
			_mainWindow.clear(sf::Color(0,0,0));
			
			_gameObjectManager.DrawAll(_mainWindow);
			
			_mainWindow.display();
			
			if(currentEvent.type == sf::Event::Closed)
				_gameState = Game::Exiting;
			
			if(currentEvent.type == sf::Event::KeyPressed)
			{
				if(currentEvent.key.code == sf::Keyboard::Escape)
					ShowMenu();
			}
			break;
		}
		
		case Game::ShowingSplash:
		{
			ShowSplashScreen();
			break;
		}
		
		case Game::ShowingMenu:
		{
			ShowMenu();
			break;
		}
		
		case Game::Exiting:
			break;
		case Game::Paused:
			break;
			
	}
}

Game::GameState Game::_gameState = Uninitialized;
sf::RenderWindow Game::_mainWindow;
GameObjectManager Game::_gameObjectManager;