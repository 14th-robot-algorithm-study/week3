#include <iostream>
#include <cstring>

int max;
int arr[4][4];
int max_y, max_x;

int rectSum(int y, int x) {
	int sum = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			int ny = y + i;
			int nx = x + j;

			if (ny >= 0 && nx >= 0 && ny < 4 && nx < 4) {
				sum += arr[ny][nx];
			}
		}
	}

	return sum;
}

int main() {
	std::memset(arr, 0, sizeof(arr));


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			if (max < rectSum(i, j)) {
				max = rectSum(i, j);
				max_y = i;
				max_x = j;
			}
		}
	}

	std::cout << "(" << max_y << "," << max_x << ")";

	return 0;
}
