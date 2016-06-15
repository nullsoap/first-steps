// mainmenu.cpp

#include "mainmenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{
	// load menu image from file
	sf::Texture texture;
	texture.loadFromFile("img/mainmenu.png");
	sf::Sprite sprite(texture);
	
	// setup clickable regions
	
	// Play menu item
	MenuItem playButton;
	playButton.rect.top = 145;
	playButton.rect.height = 235;
	playButton.rect.left = 0;
	playButton.rect.width = 1023;
	playButton.action = Play;
	
	// Exit menu item
	// note to self: see if i can render buttons with SFML features
	MenuItem exitButton;
	exitButton.rect.top = 383;
	exitButton.rect.height = 177;
	exitButton.rect.left = 0;
	exitButton.rect.width = 1023;
	exitButton.action = Exit;
	
	_menuItems.push_back(playButton);
	_menuItems.push_back(exitButton);
	
	window.draw(sprite);
	window.display();
	
	return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
	std::list<MenuItem>::iterator it;
	
	// iterate over _menuItems
	for( it = _menuItems.begin(); it != _menuItems.end(); it++)
	{
		// copy the rect pointed to by it
		sf::Rect<int> menuItemRect = it->rect; // revisions as suggested from comments 2016-06-15
		if( menuItemRect.contains(sf::Vector2<int>(x, y)))
			{
				return it->action; // return the action of the original rect.
			}
	}
	
	return Nothing;
}

MainMenu::MenuResult MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
	sf::Event menuEvent;
	
	while(true)
	{
		while(window.pollEvent(menuEvent))
		{
			if(menuEvent.type == sf::Event::MouseButtonPressed)
			{
				return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
			}
			if(menuEvent.type == sf::Event::Closed)
			{
				return Exit;
			}
		}
	}
}
