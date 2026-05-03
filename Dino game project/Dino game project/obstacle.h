#pragma once
#include <SFML/Graphics.hpp>

class Obstacle {
private:
	float obstacleGroundHeight;
	float obstacleHorizontalLocation;
	float speed;
	float OGspeed;
	sf::CircleShape obstacleSprite;

public:
	Obstacle(float obHeight = 800.f, float obHorizon = 2000.f, float obSpeed = -1.f) : speed(obSpeed), OGspeed(obSpeed), obstacleGroundHeight(obHeight), obstacleHorizontalLocation(obHorizon), obstacleSprite(50.f) {
		obstacleSprite.setPosition(sf::Vector2f(obstacleHorizontalLocation, obstacleGroundHeight));
	}

	void moveObastacle();
	void resetObstacle();
	void resetRandomObstacle(int randomness);
	void forceResetObstacle();
	void draw(sf::RenderWindow& window);
	sf::CircleShape getObstacleSprite();
};