#include <iostream>
#include <vector>
#include "Board.h"
#include "Position.h"
#include "GameManager.h"
#include "Game.h"

void print(int** b, int size);

int main() {

	// board �ʱ�ȭ
	// �� ���� 0, player 1�� 1, player 2�� 2�� �ʱ�ȭ
	int size;
	std::cin >> size;

	if (size < 4) {
		printf("�ʹ� ���� ���ڸ� �Է��Ͽ����ϴ�.");
		return 0;
	}

	// Board �����ڿ��� ó�� �߾� 4���� ���� ���� ������
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