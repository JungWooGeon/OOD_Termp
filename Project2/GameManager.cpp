#include "GameManager.h"

GameManager* GameManager::instance_ = nullptr;
GameManager* GameManager::GetManager() {
    if (!instance_) {
        instance_ = new GameManager();
    }
    return instance_;
}
GameManager::GameManager() {}

void GameManager::setP1(std::vector<Position> p1) {
	p1_ = p1;
}
void GameManager::setP2(std::vector<Position> p2) {
	p2_ = p2;
}
void GameManager::setSize(int size) {
	size_ = size;
}
void GameManager::setTurn(int turn) {
	turn_ = turn;
}

std::vector<Position> GameManager::Possible(int** board) {
	std::vector<Position>::iterator iter;
	std::vector<Position> possible;
	std::vector<Position> player;

	if (turn_ == 1) {
		player = p1_;
	}
	else {
		player = p2_;
	}

	int dx[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
	int dy[] = { 1, 0, -1, 0, 1, -1, -1, 1 };

	for (iter = player.begin(); iter != player.end(); iter++) {
		int x = iter->getX();
		int y = iter->getY();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= size_ || ny >= size_)
				continue;

			// check input possible
			if (board[x][y] != board[nx][ny] && board[nx][ny] != 0) {
				while (true) {
					nx = nx + dx[i];
					ny = ny + dy[i];

					if (nx < 0 || ny < 0 || nx >= size_ || ny >= size_)
						break;

					if (board[x][y] == board[nx][ny])
						break;
					if (board[nx][ny] == 0) {
						possible.push_back(Position(nx, ny));
						break;
					}
				}
			}
		}
	}

	return possible;
}

bool GameManager::isFull(int** b_, int size_) {
	bool isTrue = true;
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < size_; j++) {
			if (b_[i][j] != 0) {
				isTrue = false;
				break;
			}
		}
		if (!isTrue)
			break;
	}
	return isTrue;
}

bool GameManager::isAll(int** b_, int size_) {
	bool isTrue = true;
	int p1_count = 0;
	int p2_count = 0;
	for (int i = 0; i < size_; i++) {
		for (int j = 0; j < size_; j++) {
			if (b_[i][j] == 1) {
				p1_count += 1;
			}
			else if (b_[i][j] == 2) {
				p2_count += 2;
			}

			if (p1_count >= 1 && p2_count >= 1) {
				isTrue = false;
				break;
			}
		}
		if (!isTrue)
			break;
	}
	return isTrue;
}