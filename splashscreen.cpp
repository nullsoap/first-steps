#include <iostream>
#include "splashscreen.h"

void SplashScreen::Show(sf::RenderWindow& renderWindow)
{
	sf::Image image;
	if(image.loadFromFile("img/nullsoap.png") != true)
	{
		std::cout << "Error loading file: img/nullsoap.png" << std::endl;
		return;
	}
	
	sf::Texture texture;
	if(texture.loadFromImage(image) != true)
	{
		std::cout << "Error loading texture!" << std::endl;
		return;
	}
	sf::Sprite sprite(texture);
	
	renderWindow.draw(sprite);
	renderWindow.display();
	
	sf::Event event;
	while(true)
	{
		while(renderWindow.pollEvent(event))
		{
			if(event.type == sf::Event::KeyPressed
			|| event.type == sf::Event::MouseButtonPressed
			|| event.type == sf::Event::Closed )
			{
				return;
			}
		}
	}
}