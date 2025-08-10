#include <iostream>

int arr[5][4];

bool chk(int y, int x) {
	int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
	int dx[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 5 || nx >= 4) {
			continue;
		}

		if (arr[ny][nx] == 1) {
			return true;
		}
	}

	return false;


}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1) {
				if (chk(i, j)) {
					std::cout << "불안정한 상태";
					return 0;
				}
			}
		}
	}

	std::cout << "안정된 상태";
	return 0;
}
