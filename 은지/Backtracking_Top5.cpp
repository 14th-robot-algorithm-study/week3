#include <iostream>

int N;
int total_cnt;
int visited[11];
int arr[11][11];

void chess(int lev, int cnt) {
	if (cnt == N) {
		total_cnt++;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) {
			continue;
		}

		if (arr[lev][i] == 2) {
			continue;
		}

		visited[i]  = 1;
		arr[lev][i] = 2;
		chess(lev + 1, cnt + 1);
		visited[i]  = 0;
		arr[lev][i] = 1;
	}

}

int main() {
	std::cin >> N;

	chess(0, 0);
	std::cout << total_cnt;

	return 0;
}
