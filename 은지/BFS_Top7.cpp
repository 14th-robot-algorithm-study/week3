#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, R, K, res;
int bus[11] = { };
int visited[11];
vector <int> v[11];

void bfs(int st) {
	queue <int> q;
	visited[st] = 1;
	bus[st] = 0;
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
			bus[next] = bus[cur] + 1;
			q.push(next);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		if (bus[i] > 0 && bus[i] <= K) {
			res++;
		}
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

	std::cin >> R >> K;

	bfs(R);
	std::cout << res + 1;	// R번 지역을 포함하기 위해 +1

	return 0;
}
