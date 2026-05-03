#pragma once
#include <SFML/Graphics.hpp>
#include "button.h"
#include "scoreStore.h"

class MainMenu {
private:
	sf::RenderWindow& window;
	sf::Font font;
	sf::Text title;
	sf::Text scoresTitle;
	sf::Texture texture;
	sf::Sprite instructions;
	std::vector<sf::Text>nameTextStore;
	std::vector<sf::Text>scoreTextStore;
	ScoreStore scoreStore;
	Button startGame;
public:
	MainMenu(sf::RenderWindow& globalWindow) : window(globalWindow), font("consola.ttf"), title(font), scoresTitle(font), startGame(sf::Vector2f(280.f, 75.f), "START GAME", sf::Vector2f(850.f, 400.f), 50), texture("Instructions.drawio.png"), instructions(texture) {
		scoreStore.scoreFileRead();
		std::vector<Score> leaderboard = scoreStore.getLeaderboard();

		int leaderboardCount = std::min((int)leaderboard.size(), 3);
		int rowSpace = 80;

		for (int i = 0; i < leaderboardCount; i++) {
			sf::Text nameText(font);
			nameText.setString(leaderboard[i].getName());
			nameText.setPosition({ 700.f, 700.f + (i * rowSpace) });
			nameTextStore.push_back(nameText);
			
			sf::Text scoreText(font);
			scoreText.setString(std::to_string(leaderboard[i].getScore()));
			scoreText.setPosition({ 1200.f, 700.f + (i * rowSpace) });
			scoreTextStore.push_back(scoreText);
		}
		
		scoresTitle.setString("HIGH SCORES");
		title.setString("BALL GAME");

		title.setCharacterSize(100);
		title.setFillColor(sf::Color::Green);
		title.setStyle(sf::Text::Bold);
		scoresTitle.setCharacterSize(50);
		scoresTitle.setStyle(sf::Text::Bold);

		title.setPosition({ 750.f, 100.f });
		scoresTitle.setPosition({ 850.f, 600.f });
		instructions.setPosition({ 1500.f, 600.f });
		instructions.setScale(sf::Vector2(1.5f, 1.5f));

	}

	void renderMenu();

};