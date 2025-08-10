// [방법 1]
// ---------------------------------------------------------------
#include <iostream>
#include <string>

struct sketchbook {
	int image[3][3];
};

int main() {
	sketchbook value;
	std::string str[3];

	for (int i = 0; i < 3; i++) {
		std::cin >> str[i];
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			value.image[i][j] = str[i][j];
		}
	}

	int arr[150] = {};
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[value.image[i][j]] = 1;
		}
	}


	for (int i = 0; i < 150; i++) {
		if (arr[i] == 1) {
			std::cout << (char)i;
		}
	}

	return 0;
}
// ---------------------------------------------------------------


// [방법 2]
// ---------------------------------------------------------------
#include<iostream>
using namespace std;

struct sketchbook {
	char image[3][4];
};

int main() {
	sketchbook SB;
	for (int i = 0; i < 3; i++) {
		cin >> SB.image[i];
	}
	char bucket[200] = { 0 };
	char ch;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			ch = SB.image[y][x];
			bucket[ch] = 1;
		}
	}

	for (int i = 'A'; i <= 'Z'; i++) {
		if (bucket[i] == 1) {
			cout << (char)i;
		}
	}
	return 0;
}
// ---------------------------------------------------------------
