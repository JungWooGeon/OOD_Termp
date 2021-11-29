#pragma once

class Board {
public:
	explicit Board(int size);
	int** getBoard();

private:
	int** board_;
};