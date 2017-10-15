#include <SFML/Graphics.hpp>
#include <iostream>
//Fernand Battisti
//Ex2.1
#define WINDOW_WIDTH 500.f
#define WINDOW_HEIGHT 500.f
#define FRAMERATELIMIT 60.f
#define RADIUS 50.f
#define SQUARE_WIDTH 100.f
#define SQUARE_HEIGHT 100.f

bool isColliding(sf::RectangleShape square, sf::CircleShape circle)

{
	double dx = abs(circle.getPosition().x - square.getPosition().x);
	double dy = abs(circle.getPosition().y - square.getPosition().y);

	if (dx > (square.getSize().x / 2 + circle.getRadius())) { return false; }
	if (dy > (square.getSize().y / 2 + circle.getRadius())) { return false; }

	if (dx <= (square.getSize().x / 2)) { return true; }
	if (dy <= (square.getSize().y / 2)) { return true; }

	double cornerDistance = (dx - square.getSize().x / 2)*(dx - square.getSize().x / 2) +
		(dy - square.getSize().y / 2) *(dy - square.getSize().y / 2);

	return (cornerDistance <= (circle.getRadius()*circle.getRadius()));
}
int main()
{
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Ex2.1");
	window.setSize(sf::Vector2u(WINDOW_WIDTH, WINDOW_HEIGHT));
	window.setFramerateLimit(FRAMERATELIMIT);
	sf::RectangleShape square(sf::Vector2f(SQUARE_WIDTH, SQUARE_HEIGHT));
	square.setFillColor(sf::Color::Blue);
	square.setPosition(WINDOW_WIDTH/2- SQUARE_WIDTH/2, WINDOW_HEIGHT / 2 - SQUARE_HEIGHT / 2);
	sf::CircleShape shape(RADIUS);
	shape.setFillColor(sf::Color::Green);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::Vector2f delta_move;
		//Manage inputs
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			if (shape.getPosition().x > 0.f)
			delta_move.x -= 1.0f;
			
				

		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			if (shape.getPosition().x <(WINDOW_WIDTH-shape.getRadius()*2))
			delta_move.x += 1.0f;
			
				
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (shape.getPosition().y >0.f)
			delta_move.y -= 1.0f;
			
				
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			
			if (shape.getPosition().y <(WINDOW_HEIGHT - shape.getRadius()*2))
			delta_move.y += 1.0f;
			
				
		}
		float speed = 0.8f;
		shape.setPosition(shape.getPosition() + speed*delta_move);
		
		if (isColliding(square,shape))
		{
			shape.setFillColor(sf::Color::Red);
			square.setFillColor(sf::Color::Red);
		}
		else
		{
			shape.setFillColor(sf::Color::Green);
			square.setFillColor(sf::Color::Blue);
		}
		window.clear();
		window.draw(shape);
		window.draw(square);
		std::cout << shape.getPosition().x << " " << shape.getPosition().y;
		window.display();
	}

	return 0;
}