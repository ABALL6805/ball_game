#include "obstacle.h"
#include <iostream>

void Obstacle::moveObastacle() {
	obstacleSprite.move({ speed, 0.f });
}

// Now unused - Original contant obstacle with linear increase
void Obstacle::resetObstacle() {
	if (obstacleSprite.getPosition().x < (-200.f)) {
		obstacleSprite.setPosition(sf::Vector2f(2000.f, obstacleGroundHeight));
		speed = speed - 0.01f;
	}
		
}

// New function used for random object spawning, more unpredictable, more challenge!
void Obstacle::resetRandomObstacle(int randomness) {
	if (rand() % randomness == 4 && obstacleSprite.getPosition().x < (-600.f)) {
		obstacleSprite.setPosition(sf::Vector2f(2000.f, obstacleGroundHeight));
		speed = speed - 0.01f;
	}
}

void Obstacle::forceResetObstacle() {
	obstacleSprite.setPosition(sf::Vector2f(obstacleHorizontalLocation, obstacleGroundHeight));
	speed = OGspeed;
}

void Obstacle::draw(sf::RenderWindow& window) {
	window.draw(obstacleSprite);
}

sf::CircleShape Obstacle::getObstacleSprite() {
	return obstacleSprite;
}