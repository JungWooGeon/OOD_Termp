#pragma once
#include <vector>

class Position {
public:
	explicit Position(int x, int y);
	int getX();
	int getY();

private:
	int x_;
	int y_;
};