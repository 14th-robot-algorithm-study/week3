#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, T;
int min_val = 21e8;
int visited[11];
vector <int> v[11];

void bfs(int st) {
	queue <int> q;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];

			if (visited[next]) {
				continue;
			}

			if (cur == T) {
				break;
			}

			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}

	if (visited[N]) {
		std::cout << visited[N];
	}
	else {
		std::cout << -1;
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
	
	std::cin >> T;

	bfs(1);

	return 0;
}
