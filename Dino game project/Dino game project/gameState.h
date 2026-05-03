#pragma once
#include "player.h"
#include "obstacle.h"
#include "scoreStore.h"
#include <iostream>

class GameState {
private:
	sf::RenderWindow& window;
	sf::RectangleShape line;
	sf::Clock dClock;
	sf::Clock scoreClock;
	int score = 0;
	sf::Font font;
	sf::Text scoreText;
	sf::Text gameOverText;
	bool gameOver = false;
	bool saveScreen = false;
	std::string dtString;
	sf::Music music;

public:
	// Constructor
	GameState(sf::RenderWindow& globalWindow) : window(globalWindow), line({ 2000.f, 5.f }), font("consola.ttf"), scoreText(font), gameOverText(font) {
		
		if (!music.openFromFile("Game Theme.ogg")) {
			std::cout << "ERROR -- Music file failed to load\n";
		}
		line.setPosition(sf::Vector2f(0.f, 900.f));
		scoreText.setPosition(sf::Vector2f(950.f, 400.f));
		gameOverText.setPosition(sf::Vector2f(950.f, 500.f));
	}

	void checkGameOver(sf::CircleShape player, sf::CircleShape obstacle);
	
	void runGame(Player player, Obstacle obstacle, Obstacle randObstacle);


};