#include <iostream>
#include <vector>
#include "Board.h"
#include "Position.h"
#include "GameManager.h"
#include "Game.h"

void print(int** b, int size);

int main() {

	// board 초기화
	// 빈 곳은 0, player 1은 1, player 2는 2로 초기화
	int size;
	std::cin >> size;

	if (size < 4) {
		printf("너무 작은 숫자를 입력하였습니다.");
		return 0;
	}

	// Board 생성자에서 처음 중앙 4곳에 대한 값은 설정됨
	Board board(size);
	int** b = board.getBoard();

	Game game(size, b);

	// print board
	print(b, size);

	game.Play();

	return 0;
}

void print(int** b, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}