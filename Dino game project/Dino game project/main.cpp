#include "gameState.h"
#include "mainMenu.h"

void main() {
	srand(time(0));

	// Global window object that is passed to both screen classes as a reference
	sf::RenderWindow window(sf::VideoMode({ 2000, 1000 }), "Ball Game");

	GameState game(window);
	MainMenu menu(window);
	Player player;
	Obstacle obstacle;
	Obstacle randObstacle(600.f, -100.f, -1.3f);

	menu.renderMenu();
	game.runGame(player, obstacle, randObstacle);
}