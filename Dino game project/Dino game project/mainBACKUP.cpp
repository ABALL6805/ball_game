#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>


void mainBACKUP()
{
	sf::RenderWindow window(sf::VideoMode({ 2000, 1000 }), "SFML Works!!");
	sf::CircleShape shape(100.f);
	sf::CircleShape shape2(50.f);
	sf::RectangleShape line({ 2000.f, 5.f });
	sf::Clock dClock;
	sf::Clock scoreClock;
	int score = 0;
	sf::Font font("arial.ttf");
	sf::Text scoreText(font);
	sf::Text gameOverText(font);
	shape.setFillColor(sf::Color::Green);
	line.setPosition(sf::Vector2f(0.f, 900.f));
	shape.setPosition(sf::Vector2f(100.f, 700.f));
	shape2.setPosition(sf::Vector2f(2000.f, 800.f));
	scoreText.setPosition(sf::Vector2f(500.f, 500.f));
	gameOverText.setPosition(sf::Vector2f(500.f, 500.f));

	const float gravity = 2000.f;
	const float jumpForce = -1000.f;
	float yVelocity = 0.f;
	bool isJumping = false;
	bool gameOver = false;

	while (window.isOpen())
	{
		while (const std::optional event = window.pollEvent())
		{
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		while (!gameOver) {
			float deltaTime = dClock.restart().asSeconds();
			score = static_cast<int>(scoreClock.getElapsedTime().asSeconds() * 10);

			std::string dtString = std::to_string(score);

			scoreText.setString(dtString);

			window.clear();
			window.draw(shape);
			window.draw(shape2);
			window.draw(line);
			window.draw(scoreText);
			shape2.move({ -1.f, 0.f });
			window.display();


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && !isJumping)
				yVelocity = jumpForce;
			yVelocity += gravity * deltaTime;
			shape.move({ 0.f, yVelocity * deltaTime });

			if (shape.getPosition().y < 700.f)
			{
				isJumping = true;
			}

			if (shape.getPosition().y > 700.f) //Change this to a local variable "floor height" later
			{
				isJumping = false;
				shape.setPosition(sf::Vector2f(100.f, 700.f));
				yVelocity = 0.f;
			}

			if (shape2.getPosition().x == (-200.f))
				shape2.setPosition(sf::Vector2f(2000.f, 800.f));

			if (shape2.getGlobalBounds().findIntersection(shape.getGlobalBounds()))
				gameOver = true;

		}

		window.clear();
		gameOverText.setString("GAME OVER");
		window.draw(gameOverText);
		window.display();

			
	}
}