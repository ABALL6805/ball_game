#include "scoreStore.h"

void ScoreStore::scoreFileRead() {
	std::ifstream scoreFile("scores.txt");
	Score scoreTemp;
	std::string line;

	if (!scoreFile.is_open()) {
		std::ofstream newFile("scores.txt");
		return;
	}

	else {
		while (!scoreFile.eof()) {
			std::getline(scoreFile, line);
			int comma = line.find(',');
			if (comma != std::string::npos) {
				scoreTemp.setName(line.substr(0, comma));
				scoreTemp.setScore(std::stoi(line.substr(comma + 1)));
				leaderboard.push_back(scoreTemp);
			}
		}
		scoreFile.close();
	}
}

void ScoreStore::saveScore(std::string playerName, int playerScore) {
	Score newScore(playerName, playerScore);
	
	for (int i = 0; i < leaderboard.size(); i++) {
		if (playerScore > leaderboard[i].getScore()) {
			leaderboard.insert(leaderboard.begin() + i, newScore);
			scoreFileWrite();
			return;
		}
	}

	leaderboard.push_back(newScore);
	scoreFileWrite();
}

void ScoreStore::scoreFileWrite() {
	std::ofstream scoreFile("scores.txt");
	for (Score scoreTemp : leaderboard) {
		scoreFile << scoreTemp.getName() << "," << scoreTemp.getScore() << "\n";
	}
	scoreFile.close();
}

std::vector<Score> ScoreStore::getLeaderboard() {
	return leaderboard;
}