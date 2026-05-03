#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>



class Player {
private:
	const float gravity = 2000.f;
	const float jumpForce = -1000.f;
	float yVelocity = 0.f;
	bool isJumping = false;
	float playerGroundHeight = 700.f;
	bool keyReleased = false;
	int count = 0;
	sf::SoundBuffer jumpBuffer;
	sf::SoundBuffer slamBuffer;
	sf::Sound jumpEffect;
	sf::Sound slamEffect;
	sf::CircleShape playerSprite;

public:
	// Constructor - Set player sprite size
	Player() : playerSprite(100.f), jumpBuffer("jump.flac"), slamBuffer("slam.flac"), jumpEffect(jumpBuffer), slamEffect(slamBuffer) {
		playerSprite.setFillColor(sf::Color::Green);
		playerSprite.setPosition(sf::Vector2f(100.f, playerGroundHeight));
	}

	void input(float deltaTime);
	void playerJumping();
	void isKeyReleased(sf::Event event);
	void playerOnGround();
	void draw(sf::RenderWindow& window);
	sf::CircleShape getPlayerSprite();
};