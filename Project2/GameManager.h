#pragma once
#include <vector>
#include "Position.h"

class GameManager {
public:
    static GameManager* GetManager();
    std::vector<Position> Possible(int** board);
    void setP1(std::vector<Position> p1);
    void setP2(std::vector<Position> p2);
    void setSize(int size);
    void setTurn(int turn);
    bool isFull(int** b_, int size_);
    bool isAll(int** b_, int size_);

private:
    GameManager();
    static GameManager* instance_;
    std::vector<Position> p1_;
    std::vector<Position> p2_;
    int size_;
    int turn_;
};
