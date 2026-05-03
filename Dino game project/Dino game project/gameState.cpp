#include "gameState.h"
#include "button.h"
#include "textField.h"
#include <iostream>

void GameState::checkGameOver(sf::CircleShape player, sf::CircleShape obstacle) {
	if (player.getGlobalBounds().findIntersection(obstacle.getGlobalBounds())) {
		gameOver = true;
	}
}

void GameState::runGame(Player player, Obstacle obstacle, Obstacle randObstacle) {
	// Reset score clock so time spent in menu isn't counted towards score
	scoreClock.restart();
	// Initialise restart button and name text field
	Button restart(sf::Vector2f(150.f, 50.f), "RESTART", sf::Vector2f(950.f, 750.f));
	TextField name(sf::Vector2f(700.f, 60.f), "Name: ", sf::Vector2f(700.f, 600.f));
	// Create and initialise leaderboard vector
	ScoreStore leaderboard;
	leaderboard.scoreFileRead();
	std::string playerName;

	// Game Window Block
	while (window.isOpen()) {
		while (const std::optional event = window.pollEvent())
		{
			// Checks if window close button is pressed
			if (event->is<sf::Event::Closed>())
				window.close();

			player.isKeyReleased(*event);

			// Checks for entered text and moves to save screen if enter button is pushed (If the player has entered a name)
			if (gameOver && !saveScreen) {
				name.listenForText(*event);
				if (name.listenForEnter(*event)) {
					playerName = name.getInput();
					leaderboard.saveScore(playerName, score);
					saveScreen = true;
				}
			}

		}

		// Game logic and rendering block
		if (!gameOver) {

			if (music.getStatus() != sf::Music::Status::Playing) {
				music.play();
			}

			// Restarts detal clock every frame
			float deltaTime = dClock.restart().asSeconds();

			// Converts score Clock to a displayable string for the score counter on screen
			score = static_cast<int>(scoreClock.getElapsedTime().asSeconds() * 10);
			dtString = std::to_string(score);
			scoreText.setString(dtString);

			// Render block
			window.clear();
			player.draw(window);
			obstacle.draw(window);
			randObstacle.draw(window);
			window.draw(line);
			window.draw(scoreText);
			obstacle.moveObastacle();
			randObstacle.moveObastacle();
			window.display();

			// Checks for player input and player state
			player.input(deltaTime);

			player.playerJumping();

			player.playerOnGround();

			// Reset obstacle once past the screen
			obstacle.resetRandomObstacle(150);

			if (score > 500) {
				randObstacle.resetRandomObstacle(300);
			}
			

			checkGameOver(player.getPlayerSprite(), obstacle.getObstacleSprite());
			checkGameOver(player.getPlayerSprite(), randObstacle.getObstacleSprite());
		}

		// Game Over Screen rendering block
		else if (gameOver && !saveScreen) {
			music.stop();
			window.clear();
			gameOverText.setString("GAME OVER");
			scoreText.setString("Score: " + dtString);
			// Resets game score, obstacles, and name text field and moves back to Game Screen
			restart.draw(window);
			if (restart.mouseClick(window)) {
				obstacle.forceResetObstacle();
				randObstacle.forceResetObstacle();
				scoreClock.restart();
				name.resetInput();
				gameOver = false;
			}
			name.draw(window);
			window.draw(scoreText);
			window.draw(gameOverText);
			window.display();
		}

		// Save Screen rendering block
		else if (gameOver && saveScreen) {
			scoreText.setString(playerName + "'s score of " + dtString + " saved!");
			scoreText.setPosition(sf::Vector2f(800.f, 400.f));
			window.clear();
			restart.draw(window);
			window.draw(scoreText);
			if (restart.mouseClick(window)) {
				scoreText.setPosition(sf::Vector2f(950.f, 400.f));
				obstacle.forceResetObstacle();
				randObstacle.forceResetObstacle();
				scoreClock.restart();
				name.resetInput();
				gameOver = false;
				saveScreen = false;
			}
			window.display();
		}
		
	}
}