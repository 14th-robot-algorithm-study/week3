#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct sel {
	int a;
	int b;
	int cost;
};

int N, M, K;
vector <sel> v[11];
int dist[11];

void bfs(int st) {
	queue <int> q;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (cur == 0) {
				dist[v[cur][i].b] = v[cur][i].cost;
			}
			else {
				dist[v[cur][i].b] = dist[v[cur][i].a] + v[cur][i].cost;
			}

			q.push(v[cur][i].b);
		}

	}

}

int main() {
	std::cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int from, to, cost;
		std::cin >> from >> to >> cost;

		v[from].push_back({ from, to, cost });
	}

	bfs(0);

	for (int i = 0; i < N; i++) {
		if (0<dist[i] && dist[i] <= K) {
			std::cout << i << " ";
		}
	}
	return 0;
}
