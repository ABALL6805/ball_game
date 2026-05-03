#pragma once
#include <SFML/Graphics.hpp>

class TextField {
private:
	sf::RectangleShape boundary;
	sf::Font font;
	std::string input;
	sf::Text inputText;
	sf::Text label;
	sf::Vector2f position;

public:
	TextField(sf::Vector2f size, std::string labelText, sf::Vector2f xy) : font("consola.ttf"), inputText(font), label(font), boundary(size), position(xy) {
		label.setString(labelText);
		boundary.setPosition(position);
		label.setPosition({ position.x - (size.x/6), position.y});	// Offsets the label to the left of the text field
		inputText.setPosition({position.x + 2.f, position.y});
		boundary.setFillColor(sf::Color::Black);
		boundary.setOutlineColor(sf::Color::White);
		boundary.setOutlineThickness(2.f);
	}

	void draw(sf::RenderWindow& window);
	void listenForText(sf::Event event);
	bool listenForEnter(sf::Event event);
	std::string getInput();
	void resetInput();

};