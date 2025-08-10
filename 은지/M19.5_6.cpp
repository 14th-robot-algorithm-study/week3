#include <iostream>

int main() {
	int dy[3] = { 0, 1, 1 };
	int dx[3] = { 1, 0, 1 };

	bool flag;
	int cnt = 0;
	char map[3][4] = {
		{'A', 'B', 'G', 'K'},
		{'T', 'T', 'A', 'B'},
		{'A', 'C', 'C', 'D'}
	};

	char pattern[2][2];

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cin >> pattern[i][j];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 4; j++) {
			int ny = i;
			int nx = j;

			if (map[ny][nx] == pattern[0][0]) {
				flag = true;
				for (int k = 0; k < 3; k++) {
					ny = i + dy[k];
					nx = j + dx[k];

					if (ny >= 3 || nx >= 4) {
						flag = false;
						break;
					}

					if (map[ny][nx] != pattern[dy[k]][dx[k]]) {
						flag = false;
						break;
					}
				}

				if (flag) {
					cnt++;
				}
			}
		}
	}

	if (cnt) {
		std::cout << "발견(" << cnt << "개)";
	}
	else {
		std::cout << "미발견";
	}


	return 0;
}
