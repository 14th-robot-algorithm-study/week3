#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int Y, X, N, max_val;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int MAP[1'001][1'001];
int dist[1'001][1'001];

struct Edge {
	int y, x;
	int cost;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};

void dijkstra(int sy, int sx) {
	priority_queue <Edge, vector<Edge>, cmp> pq;
	pq.push({ sy, sx, MAP[sy][sx] });
	dist[sy][sx] = MAP[sy][sx];

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (dist[now.y][now.x] < now.cost) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
				continue;
			}

			if (MAP[ny][nx] == -1) {
				dist[ny][nx] = -1;
				continue;
			}

			int next = now.cost + MAP[ny][nx];

			if (next < dist[ny][nx]) {
				dist[ny][nx] = next;
				pq.push({ ny, nx, next });
			}
		}
	}
}

int main() {
	std::cin >> Y >> X >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> MAP[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = 21e8;
		}
	}

	dijkstra(Y, X);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (max_val < dist[i][j]) {
				max_val = dist[i][j];
			}
		}
	}

	std::cout << max_val;

	return 0;
}
