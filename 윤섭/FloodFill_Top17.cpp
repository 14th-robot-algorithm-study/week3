#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Point {
	int y, x;
};

int N, M;
int map[75][75];
int ice[75][75];
int visited[75][75];
int iceCnt;
int year;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void fire(Point cp) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		Point np = { cp.y + dy[i], cp.x + dx[i] };
		if (map[np.y][np.x] == 0) cnt++;
	}
	visited[cp.y][cp.x] = cnt;
}


void bfs(Point st) {
	queue<Point> q;
	q.push(st);
	iceCnt++;

	while (!q.empty()) {
		Point cp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			Point np = { cp.y + dy[i], cp.x + dx[i] };
			if (map[np.y][np.x] == 0) continue;
			if (ice[np.y][np.x] > 0) continue;
			ice[np.y][np.x] = iceCnt;
			q.push(np);
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	
	while (iceCnt < 2) {
		year++;
		iceCnt = 0;
		memset(visited, 0, sizeof(visited));
		memset(ice, 0, sizeof(ice));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) continue;
				fire({ i, j });
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) continue;
				map[i][j] -= visited[i][j];
				if (map[i][j] < 0) map[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0 || ice[i][j] > 0) continue;
				bfs({ i, j });
			}
		}

		if (iceCnt == 0) {
			year = 0;
			break;
		}
	}

	cout << year;

}
