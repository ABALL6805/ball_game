#pragma once
#include <string>

class Score {
private:
	std::string name;
	int score;

public:
	Score() {

	}

	Score(std::string playerName, int playerScore) {
		name = playerName;
		score = playerScore;
	}

	std::string getName() {
		return name;
	}

	int getScore() {
		return score;
	}

	void setName(std::string playerName) {
		name = playerName;
	}

	void setScore(int playerScore) {
		score = playerScore;
	}
};