#pragma once

#include <vector>
#include "Board.h"
#include "Position.h"
#include "GameManager.h"

class Game {
public:
	explicit Game(int size, int **b);
	void Play();

private:
	int turn_;
	int size_;
	int** b_;
	int stack_;
	std::vector<Position> p1_;
	std::vector<Position> p2_;
	std::vector<Position>::iterator iter_;

	GameManager* gm_;
	std::vector<Position> possible_;
};