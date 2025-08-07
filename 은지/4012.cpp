#include <iostream>
#include <algorithm>


// ==================  [1] 전역 변수 정의 ==================
int arr[16][16];
int visited[16];
int min_val;
// ========================================================


// ==================  [2] 재귀 함수 정의 ==================
void func(int idx, int lev, int N) {
	if (lev == (N / 2)) {
		int a_sum = 0;
		int b_sum = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j) {
					continue;
				}
				else if (visited[i] && visited[j]) {
					a_sum += arr[i][j];
				}
				else if (!visited[i] && !visited[j]) {
					b_sum += arr[i][j];
				}
			}
		}

		int tmp = abs(a_sum - b_sum);
		min_val = std::min(min_val, tmp);

		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			func(i + 1, lev + 1, N);
			visited[i] = 0;
		}
	}
}
// ========================================================


// ==================  [3] 재귀 함수 호출 ==================
int main() {
	int T;
	std::cin >> T;

	for (int i = 1; i < T + 1; i++) {
		int N;
		std::cin >> N;

		min_val = 9999;
		std::fill(visited, visited + N, 0);

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cin >> arr[i][j];
			}
		}

		func(0, 0, N);
		std::cout << "#" << i << " " << min_val << "\n";
	}

	return 0;
}
// ========================================================
