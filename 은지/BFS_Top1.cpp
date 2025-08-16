#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[11][11];
int visited[11];

void bfs(int st) {
	queue <int> q;
	q.push(st);
	visited[st] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		std::cout << cur << " ";

		for (int i = 0; i < N; i++) {
			if (visited[i]) {
				continue;
			}
			
			if (arr[cur][i] == 0) {
				continue;
			}

			visited[i] = 1;
			q.push(i);
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
		}
	}

	bfs(0);

	return 0;
}
