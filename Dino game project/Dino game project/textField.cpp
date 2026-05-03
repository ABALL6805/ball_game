#include "textField.h"

void TextField::draw(sf::RenderWindow& window) {
	window.draw(boundary);
	window.draw(inputText);
	window.draw(label);
}

void TextField::listenForText(sf::Event event) {
	if (const auto* textEvent = event.getIf<sf::Event::TextEntered>()) {	// Provides the pointer to the event data to retrieve entered letter
		char32_t inputChar = textEvent->unicode;

		if (inputChar == 8) {	// Handles backspace
			if (!input.empty()) {
				input.pop_back();
			}
		}
		else if (inputChar == 13) {	// Ignore enter input
			return;
		}
		else {
			input += static_cast<char>(inputChar);	// Append entered text to input string
		}

		inputText.setString(input);
	}
}

bool TextField::listenForEnter(sf::Event event) {
	if (const auto* enterEvent = event.getIf<sf::Event::KeyPressed>()) {
		if ((enterEvent->code == sf::Keyboard::Key::Enter) && input.length() > 0) {
			return true;
		}
	}
	return false;
}

std::string TextField::getInput() {
	return input;
}

void TextField::resetInput() {
	input = "";
}