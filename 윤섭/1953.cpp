#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct Point {
	int y, x, type;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int connect[8][4] = {
	0, 0, 0, 0,
	1, 1, 1, 1,
	1, 1, 0, 0,
	0, 0, 1, 1,
	1, 0, 0, 1,
	0, 1, 0, 1,
	0, 1, 1, 0,
	1, 0, 1, 0
};

int T, N, M, R, C, L;
int ans;
vector<vector<int>> map;
vector<vector<int>> visited;

void bfs(Point st) {
	queue<Point> q;
	visited[st.y][st.x] = 1;
	q.push(st);

	while (!q.empty()) {
		Point cp = q.front();
		q.pop();

		if (visited[cp.y][cp.x] == L) continue;

		for (int dir = 0; dir < 4; dir++) {
			if (connect[cp.type][dir] == 0) continue;

			int ny = cp.y + dy[dir];
			int nx = cp.x + dx[dir];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;
			if (map[ny][nx] == 0) continue;

			int ndir;

			if (dir == 0) ndir = 1;
			else if (dir == 1) ndir = 0;
			else if (dir == 2) ndir = 3;
			else if (dir == 3) ndir = 2;

			if (connect[map[ny][nx]][ndir] == 0) continue;

			if (!visited[ny][nx]) {
				visited[ny][nx] = visited[cp.y][cp.x] + 1;
				q.push({ ny, nx, map[ny][nx] });
			}
		}
	}
}

int main()
{
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		cin >> N >> M >> R >> C >> L;

		map.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<int>(M, 0));
		ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j];
			}
		}
		bfs({ R, C , map[R][C] });

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (visited[i][j] > 0 && visited[i][j] <= L) ans++;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}
