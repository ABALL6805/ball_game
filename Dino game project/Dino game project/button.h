#pragma once
#include <SFML/Graphics.hpp>

class Button {
private:
	sf::RectangleShape boundary;
	sf::Font font;
	sf::Text text;
	sf::Vector2f position;
	sf::Color buttonColor;
	sf::Color textColor;

public:
	Button(sf::Vector2f size, std::string buttonText, sf::Vector2f xy, int fontSize = 36, sf::Color bColor = sf::Color::White, sf::Color tColor = sf::Color::Black) : font("consola.ttf"), text(font), boundary(size), position(xy), buttonColor(bColor), textColor(tColor) {
		text.setString(buttonText);
		boundary.setPosition(position);
		text.setPosition(position);
		boundary.setFillColor(buttonColor);
		text.setFillColor(textColor);
		text.setStyle(sf::Text::Bold);
		text.setCharacterSize(fontSize);
	}

	void draw(sf::RenderWindow& window);
	sf::Vector2f detectMouse(sf::RenderWindow& window);
	bool mouseHovering(sf::RenderWindow& window);
	bool mouseClick(sf::RenderWindow& window);
	void resetColor();
};