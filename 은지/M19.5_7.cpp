// [방법 1]
// -----------------------------------------------------------
#include <iostream>
#include <algorithm>

int main() {
	int sum;
	int max_y, max_x;
	int max_val = -21e8;

	int map[3][3] = {
		{3, 5, 1},
		{3, 8, 1},
		{1, 1, 5}
	};

	int bitarray[2][2];
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			std::cin >> bitarray[i][j];
		}
	}

	for (int i = 0; i < 3 - 2 + 1; i++) {
		for (int j = 0; j < 3 - 2 + 1; j++) {
			sum = 0;

			sum += map[i][j] * bitarray[0][0];
			sum += map[i][j+1] * bitarray[0][1];
			sum += map[i+1][j] * bitarray[1][0];
			sum += map[i + 1][j + 1] * bitarray[1][1];

			if (max_val < sum) {
				max_y = i;
				max_x = j;
				max_val = sum;
			}
		}
	}

	std::cout << "(" << max_y << "," << max_x << ")";

	return 0;
}
// -----------------------------------------------------------


// [방법 2]
// -----------------------------------------------------------
#include <iostream>
using namespace std;

int map[3][3] =
{
	3, 5, 1,
	3, 8, 1,
	1, 1, 5,
};

int bitarray[2][2];

int getSum(int dx, int dy)
{
	int x, y;
	int sum = 0;

	for (y = 0; y < 2; y++) {
		for (x = 0; x < 2; x++) {
			if (bitarray[y][x] == 1) {
				sum += map[dy + y][dx + x];
			}
		}
	}
	return sum;
}

int main()
{
	int x, y;

	for (y = 0; y < 2; y++) {
		for (x = 0; x < 2; x++) {
			cin >> bitarray[y][x];
		}
	}

	int sum = 0;
	int max = -9999;
	int mx, my;

	for (y = 0; y < 2; y++) {
		for (x = 0; x < 2; x++) {
			sum = getSum(x, y);
			if (sum > max) {
				max = sum;
				mx = x;
				my = y;
			}
		}
	}

	cout << "(" << my << "," << mx << ")";

	return 0;
}
// -----------------------------------------------------------
