#include <iostream>
using namespace std;

struct Input {
	int y, x;
};

int main() {
	Input input[4];
	int arr[4][3] = { };

	for (int i = 0; i < 4; i++) {
		std::cin >> input[i].y >> input[i].x;
	}


	for (int i = 0; i < 4; i++) {
		arr[input[i].y][input[i].x] = 5;
	}

	for (int i = 0; i < 4; i++) {
		for (int j : arr[i]) {
			std::cout << j << " ";
		}
		std::cout << '\n';
	}

	return 0;
}
