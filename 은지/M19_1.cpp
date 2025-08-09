#include <iostream>
using namespace std;

struct Point {
	int x, y;
};


int main() {
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };

	int arr[3][3] = {
		{3, 5, 4},
		{1, 1, 2},
		{1, 3, 9}
	};

	Point point;
	std::cin >> point.y >> point.x;

	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int ny = point.y + dy[i];
		int nx = point.x + dx[i];

		if (nx < 0 || ny < 0 || ny >= 3 || nx >= 3) {
			continue;
		}

		sum += arr[ny][nx];
	} 

	std::cout << sum;

	return 0;
}
