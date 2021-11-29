#include "Board.h"

Board::Board(int size) {
	this->board_ = new int* [size];
	for (int i = 0; i < size; i++)
		board_[i] = new int[size];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			board_[i][j] = 0;
	}
	
	board_[(size / 2) - 1][(size / 2) - 1] = 1;
	board_[(size / 2) - 1][(size / 2)] = 2;
	board_[(size / 2)][(size / 2) - 1] = 2;
	board_[(size / 2)][(size / 2)] = 1;
}

int** Board::getBoard() {
	return this->board_;
}