#include "Position.h"

Position::Position(int x, int y) : x_(x), y_(y) {}

int Position::getX() { return x_; }
int Position::getY() { return y_; }