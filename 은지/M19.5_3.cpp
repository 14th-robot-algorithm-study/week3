#include <iostream>

int main() {
	int arr[4][4];
	int tmp = 1;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = tmp;
			tmp++;
		}
	}

	tmp = 1;
	int chk[4];
	for (int i = 0; i < 4; i++) {
		std::cin >> chk[i];
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (chk[tmp-1] == arr[i][j]) {
				arr[i][j] = tmp;
				tmp++;
			}

			else {
				arr[i][j] = 0;
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
