#include <iostream>
#include <queue>

using namespace std;

int N, M;
int map[100][100];
int visited[100][100];

struct Point {
	int y, x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int cnt;
void func(Point st) {
	queue<Point> q;
	q.push(st);

	while (!q.empty()) {
		Point cp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Point np = { cp.y + dy[i], cp.x + dx[i] };
			if (np.y < 0 || np.x < 0 || np.y >= N || np.x >= M)continue;
			if (map[np.y][np.x] == 0) continue;
			if (visited[np.y][np.x] == 1) continue;
			map[np.y][np.x] = 0;
			q.push(np);
		}
	}

	cnt++;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) continue;
			func({ i, j });
		}
	}

	cout << cnt;
}
