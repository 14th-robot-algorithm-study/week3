#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N, useGas;
int move_y, move_x;
int nextGas;
int arr[31][31];
int gas[31][31];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

struct Edge {
	int y, x;
	int gas;
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.gas > b.gas;
	}
};

void dijkstra(Edge st) {
	priority_queue <Edge, vector<Edge>, cmp> pq;
	gas[st.y][st.x] = st.gas;
	pq.push(st);

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (gas[now.y][now.x] < now.gas) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= N) {
				continue;
			}


			if (arr[now.y][now.x] < arr[ny][nx]) {
				if (gas[now.y][now.x] + (2 * (abs(arr[now.y][now.x] - arr[ny][nx]))) > gas[ny][nx]) {
					continue;
				}
				gas[ny][nx] = gas[now.y][now.x] + (2 * (abs(arr[now.y][now.x] - arr[ny][nx])));
				pq.push({ ny, nx, gas[ny][nx] });
			}
			else if (arr[now.y][now.x] == arr[ny][nx]) {
				if (gas[now.y][now.x] + 1 > gas[ny][nx]) {
					continue;
				}
				gas[ny][nx] = gas[now.y][now.x] + 1;
				pq.push({ ny, nx, gas[ny][nx] });
			}
			else {
				if (gas[now.y][now.x] + 0 > gas[ny][nx]) {
					continue;
				}
				gas[ny][nx] = gas[now.y][now.x] + 0;
				pq.push({ ny, nx, gas[ny][nx] });
			}

		}
	}
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			gas[i][j] = 21e8;
		}
	}
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 1; i < T + 1; i++) {

		std::cin >> N;
		init();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				std::cin >> arr[i][j];
			}
		}

		dijkstra({ 0, 0, 0 });

		std::cout << "#" << i << " " << gas[N - 1][N - 1] << '\n';
	}

	return 0;
}
