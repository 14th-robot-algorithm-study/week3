#include <iostream>
#include <algorithm>

int N;
int min_val = 21e8;
int arr[100][100];
int visited[100];


void func(int lev, int count, int cnt) {
	if (cnt == N) {
		if (arr[lev][0] != 0) {
			count += arr[lev][0];
			min_val = std::min(min_val, count);
		}

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
		func(i, count + arr[lev][i], cnt + 1);
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

	visited[0] = 1;
	func(0, 0, 1);

	std::cout << min_val;
	return 0;
}
