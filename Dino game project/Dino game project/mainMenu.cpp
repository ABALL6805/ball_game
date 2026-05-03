#include "mainMenu.h"

void MainMenu::renderMenu() {
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent()) {
			if (event->is<sf::Event::Closed>())
				window.close();
		}

		window.clear();
		window.draw(title);
		startGame.draw(window);
		window.draw(instructions);
		if (startGame.mouseClick(window)) {
			// Exits menu loop and moves to game
			break;
		}

		// Leaderboard render block
		window.draw(scoresTitle);

		for (sf::Text name : nameTextStore) {
			window.draw(name);
		}

		for (sf::Text score : scoreTextStore) {
			window.draw(score);
		}

		window.display();
	}
}