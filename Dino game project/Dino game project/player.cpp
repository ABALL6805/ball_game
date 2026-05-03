#include "player.h"

void Player::input(float deltaTime) {
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && !isJumping) {
		yVelocity = jumpForce;
		jumpEffect.play();
		count = 1;
	}
	else if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) && isJumping && keyReleased && count == 1) {
		yVelocity = jumpForce;
		jumpEffect.play();
		count = 2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		yVelocity = -(jumpForce - 500);
		slamEffect.play();
	}
	yVelocity += gravity * deltaTime;	// Using deltaTime makes game physics framerate independent
	playerSprite.move({ 0.f, yVelocity * deltaTime });
}

void Player::playerJumping() {
	if (playerSprite.getPosition().y < playerGroundHeight) {
		isJumping = true;
	}
}

// Checks if player has released jump key from first jump before couning the second jump
void Player::isKeyReleased(sf::Event event) {
	if (const auto* releaseEvent = event.getIf<sf::Event::KeyReleased>()) {
		if (releaseEvent->code == sf::Keyboard::Key::Up || releaseEvent->code == sf::Keyboard::Key::W) {
			keyReleased = true;
		}
	}
}

// Stops player from moving once they hit the ground
void Player::playerOnGround() {
	if (playerSprite.getPosition().y > playerGroundHeight) {
		isJumping = false;
		keyReleased = false;
		count = 0;
		playerSprite.setPosition(sf::Vector2f(100.f, playerGroundHeight));
		yVelocity = 0.f;
	}
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(playerSprite);
}

sf::CircleShape Player::getPlayerSprite() {
	return playerSprite;
}

