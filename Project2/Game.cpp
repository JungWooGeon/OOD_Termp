#include "Game.h"

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool reverse(int x, int y, int direction, int** b);
void turn_change(int *turn_);
bool isFull(int** b_, int size_);
bool isAll(int** b_, int size_);

Game::Game(int size, int** b) : size_(size), b_(b){
	gm_ = GameManager::GetManager();

	p1_.push_back(Position((size_ / 2) - 1, (size_ / 2) - 1));
	p1_.push_back(Position((size_ / 2), (size_ / 2)));
	p2_.push_back(Position((size_ / 2), (size_ / 2) - 1));
	p2_.push_back(Position((size_ / 2) - 1, (size_ / 2)));
	gm_->setSize(size_);
	gm_->setP1(p1_);
	gm_->setP2(p2_);

	turn_ = 1;
	stack_ = 0;
}

void Game::Play() {
	while (true) {
		// ���� ���� á�� ���
		if (isFull(b_, size_)) {
			printf("�ǿ� ���� ���� á���ϴ�.\n ������ �����մϴ�.\n");
			break;
		}
		// �� ���� ��� ���� �������� ���
		if (isAll(b_, size_)) {
			printf("Player %d�� �¸��Ͽ����ϴ�.", b_[0][0]);
			break;
		}

		// p1�� p2�� ���� position update
		p1_.clear();
		p2_.clear();
		for (int i = 0; i < size_; i++) {
			for (int j = 0; j < size_; j++) {
				if (b_[i][j] == 1) {
					p1_.push_back(Position(i, j));
				}
				else if (b_[i][j] == 2) {
					p2_.push_back(Position(i, j));
				}
			}
		}


		gm_->setP1(p1_);
		gm_->setP2(p2_);
		gm_->setTurn(turn_);

		possible_ = gm_->Possible(b_);

		if (possible_.empty()) {
			// ���� �Ͽ��� ������ ���� ���� ���
			stack_++;
			if (stack_ > 2) {
				printf("������ ����Ǿ����ϴ�.\n");
				break;
			}
			turn_change(&turn_);
		}
		else {
			stack_ = 0;
			// ���� ���� ���� ��ǥ�� �Է�
			while (true) {
				int input_x;
				int input_y;
				bool isTrue = false;
				for (iter_ = possible_.begin(); iter_ != possible_.end(); iter_++) {
					printf("�Է� ������ ��ǥ : %d %d\n", iter_->getX(), iter_->getY());
				}
				printf("player %d : ", turn_);
				scanf("%d %d", &input_x, &input_y);

				// �ش� ��ǥ�� ���� ���� �� �ִ��� �Ǻ�
				for (iter_ = possible_.begin(); iter_ != possible_.end(); iter_++) {
					if (input_x == iter_->getX() && input_y == iter_->getY()) {
						isTrue = true;
						break;
					}
				}

				// �ش� ��ǥ�� ���� ���� �� �ִٸ� ����
				if (isTrue) {
					// �� ����
					b_[input_x][input_y] = turn_;

					// ������
					for (int i = 0; i < 4; i++) {
						int nx = input_x + dx[i];
						int ny = input_y + dy[i];

						if (nx < 0 || ny < 0 || nx >= size_ || ny >= size_)
							continue;

						if (b_[input_x][input_y] != b_[nx][ny] && b_[nx][ny] != 0) {
							reverse(nx, ny, i, b_);
						}
					}

					for (int i = 0; i < size_; i++) {
						for (int j = 0; j < size_; j++) {
							printf("%d ", b_[i][j]);
						}
						printf("\n");
					}
					printf("\n");

					turn_change(&turn_);
					break;
				}
				else {
					printf("�ٽ� �Է����ּ���.\n");
				}
			}
		}
	}
}

bool reverse(int x, int y, int direction, int** b) {
	int nx = x + dx[direction];
	int ny = y + dy[direction];

	if (b[nx][ny] == 0)
		return false;

	if (b[x][y] == b[nx][ny]) {
		bool isTrue = reverse(nx, ny, direction, b);
		if (isTrue) {
			b[x][y] = b[nx][ny];
		}
		return isTrue;
	}
	else {
		b[x][y] = b[nx][ny];
		return true;
	}
}

void turn_change(int *turn_) {
	if (*turn_ == 1) {
		*turn_ = 2;
	}
	else {
		*turn_ = 1;
	}
}

bool isFull(int** b_, int size_) {
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

bool isAll(int** b_, int size_) {
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