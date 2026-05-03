#pragma once
#include <vector>
#include <fstream>
#include "score.h"

class ScoreStore {
private:
	std::vector<Score>leaderboard;

public:

	void scoreFileRead();
	void saveScore(std::string playerName, int playerScore);
	void scoreFileWrite();
	std::vector<Score> getLeaderboard();
};