#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct sel {
	int a;
	int b;
	int strength;
};

int N, M, K, cnt;
long long coco[100'001];
bool visited[100'001];
vector <sel> v[100'001];

void bfs(int st) {
	queue <int> q;
	q.push(st);
	visited[st] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].b;

			if (visited[next]) {
				continue;
			}

			visited[next] = true;
			coco[next] = coco[cur] + v[cur][i].strength;
			q.push(next);
		}
	}

	for (int i = 1; i < N + 1; i++) {
		if (coco[i] > 0 && coco[i] <= K) {
			cnt++;
		}
	}

}

int main() {
	std::cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int from, to, s;
		std::cin >> from >> to >> s;

		v[from].push_back({ from, to, s });
	}

	bfs(1);
	std::cout << cnt;

	return 0;
}
