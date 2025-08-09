#include <iostream>
#include <algorithm>

int map[5][5] = {
	{3, 3, 5, 3, 1},
	{2, 2, 4, 2, 6},
	{4, 9, 2, 3, 4},
	{1, 1, 1, 1, 1},
	{3, 3, 5, 9, 2}
};

// 왼 위, 오 위, 왼 아래, 오 아래
int dy[4] = { -1, -1, 1, 1 };
int dx[4] = { -1, 1, -1, 1 };

int sum(int y, int x) {
	int sum = map[y][x];

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		while (ny >= 0 && nx >= 0 && ny < 5 && nx < 5) {
			sum += map[ny][nx];
			ny += dy[i];
			nx += dx[i];
		}
	}

	return sum;
}

int main() {
	int max_sum = 0;
	int max_y, max_x;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (max_sum < sum(i, j)) {
				max_sum = sum(i, j);
				max_y = i;
				max_x = j;
			}
		}
	}
	
	std::cout << max_y << " " << max_x;
	return 0;
}
