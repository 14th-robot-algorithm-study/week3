#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Point {
	int y, x, dir, turn;
};
Point start;
int dy[4] = { 0, 1, 0, -1 };	//오른쪽부터 시계 방향
int dx[4] = { 1, 0, -1, 0 };
int N;
int map[10][10];
int visited[10][10][4];
pair <int, int> target[11];


int bfs(Point sp, pair <int, int> tp) {
	queue <Point> q;
	q.push(sp);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int d = 0; d < 4; d++)
				visited[i][j][d] = 1e9;

	visited[sp.y][sp.x][sp.dir] = sp.turn;
	int bestTurn = 1e9;
	int bestDir = sp.dir;

	while (!q.empty()) {
		Point cp = q.front();
		q.pop();

		if (cp.y == tp.first && cp.x == tp.second) {
			if (cp.turn < bestTurn) {
				bestTurn = cp.turn;
				bestDir = cp.dir;
			}
			continue;
		}

		/*=====     전진 구현     ======*/
		Point np1 = { cp.y + dy[cp.dir], cp.x + dx[cp.dir] , cp.dir, cp.turn };
		if (np1.y >= 0 && np1.x >= 0 && np1.y < N && np1.x < N) {
			if (visited[np1.y][np1.x][np1.dir] > np1.turn) {
				visited[np1.y][np1.x][np1.dir] = np1.turn;
				q.push({ np1.y, np1.x, np1.dir, np1.turn});
			}
		}

		/*=====     우회전 구현     ======*/
		Point np2 = { cp.y + dy[(cp.dir+1) % 4], cp.x + dx[(cp.dir + 1) % 4] , (cp.dir + 1) % 4, cp.turn + 1 };
		if (np2.y >= 0 && np2.x >= 0 && np2.y < N && np2.x < N) {
			if (visited[np2.y][np2.x][np2.dir] > np2.turn) {
				visited[np2.y][np2.x][np2.dir] = np2.turn;
				q.push({ np2.y, np2.x, np2.dir, np2.turn });
			}
		}
	}

	start.dir = bestDir;
	return bestTurn;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int ans = 0;
		memset(map, 0, sizeof(map));
		memset(target, -1, sizeof(target));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				if (map[i][j] != 0) {
					target[map[i][j]] = { i, j };
				}
			}
		}

		start = { 0, 0, 0, 0 };
		for (int i = 1; i <= 10; i++) {
			if (target[i].first == -1) continue;
			int cnt = bfs(start, target[i]);
			ans += cnt;
			start.y = target[i].first;
			start.x = target[i].second;
			start.turn = 0;
		}

		cout << "#" << tc << " " << ans << "\n";
	}
}
