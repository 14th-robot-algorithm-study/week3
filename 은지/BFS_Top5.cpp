#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, cnt;
int visited[101];
vector <int> v[101];

void bfs(int st) {
	queue <int> q;
	visited[st] = 1;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];

			if (visited[next]) {
				continue;
			}

			visited[next] = 1;
			q.push(next);
		}
	}

	for (int i = 0; i < N + 1; i++) {
		if (i == st || visited[i] == 0) {
			continue;
		}

		cnt++;
	}

}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		std::cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	bfs(1);
	std::cout << cnt;

	return 0;
}
