#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	int scrWidth, scrHeight;
	scrWidth = 1024;
	scrHeight = 768;
	
	sf::RenderWindow window(sf::VideoMode(scrWidth, scrHeight), "\"Bouncing\" ball");
	sf::Clock clock;
	
	sf::RectangleShape ball(sf::Vector2f(10,10));
	ball.setFillColor(sf::Color::White);
	ball.setPosition(100, 100);
	float speed = 100.f;
	bool right = true;
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				std::cout << "window closed!" << std::endl;
				window.close();
			}
		}
		
		float delta = clock.restart().asSeconds();
		
		if (ball.getPosition().x < 0) {
			right = true;
		} else if (ball.getPosition().x > scrWidth - ball.getSize().x) {
			right = false;
		}
		
		if (right) ball.move(speed * delta, 0.f);
		else ball.move(speed * delta * -1.f, 0.f);
		
		window.clear();
		window.draw(ball);
		window.display();
	}
	
	return 0;
}
