#include "button.h"
#include <windows.h>

void Button::draw(sf::RenderWindow& window) {
	window.draw(boundary);
	window.draw(text);
}

sf::Vector2f Button::detectMouse(sf::RenderWindow& window) {
	return sf::Vector2f(sf::Mouse::getPosition(window));
}

bool Button::mouseHovering(sf::RenderWindow& window) {
	if (boundary.getGlobalBounds().contains(detectMouse(window))) {
		return true;
	}
	return false;
}

bool Button::mouseClick(sf::RenderWindow& window) {
	if (mouseHovering(window) && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
		// Add a sound here for button pressing later
		return true;
	}
	return false;
}

void Button::resetColor() {
	boundary.setFillColor(buttonColor);
	text.setFillColor(textColor);
}