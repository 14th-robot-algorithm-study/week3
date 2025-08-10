#include <iostream>
#include <algorithm>

int N;
int st, en;
int max_val = -21e8;
int min_val = 21e8;
int arr[100][100];
int visited[100];


void func(int lev, int count) {
	if (lev == en) {
		max_val = std::max(max_val, count);
		min_val = std::min(min_val, count);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) {
			continue;
		}

		if (arr[lev][i] == 0) {
			continue;
		}

		visited[i] = 1;
		func(i, count + arr[lev][i]);
		visited[i] = 0;
	}
}


int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
		}
	}

	std::cin >> st >> en;

	visited[st] = 1;
	func(st, 0);

	std::cout << min_val << "\n";
	std::cout << max_val;

	return 0;
}
