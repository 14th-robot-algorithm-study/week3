#include <iostream>

struct user {
	char ch;
	int num;
};

int main() {
	int arr[4][4] = {};

	int dy[4] = { 1, 0 };
	int dx[4] = { 0, 1 };


	user val[3];
	for (int i = 0; i < 3; i++) {
		std::cin >> val[i].ch;
		std::cin >> val[i].num;

		if (val[i].ch == 'G') {
			int ny = val[i].num;
			int nx = 0;

			arr[ny][nx] = 1;

			for (int i = 0; i < 3; i++) {
				nx += dx[1];
				arr[ny][nx] = 1;
			}
		}


		if (val[i].ch == 'S') {
			int ny = 0;
			int nx = val[i].num;

			arr[ny][nx] = 1;

			for (int i = 0; i < 3; i++) {
				ny += dy[0];
				arr[ny][nx] = 1;
			}
		}
	}


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << arr[i][j] << " ";
		}
		std::cout << "\n";
	}


	return 0;
}
