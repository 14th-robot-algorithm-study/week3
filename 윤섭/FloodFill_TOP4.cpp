#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int dy[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };	//시계방향
int dx[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
struct Point {
	int y, x;
};
int h, w;
Point knight, target;
int visited[100][100];

void bfs(Point st) {
	queue<Point> q;
	visited[st.y][st.x] = 1;
	q.push(st);

	while (!q.empty()) {
		Point cp = q.front();
		q.pop();
		for (int i = 0; i < 8; i++) {
			Point np = { cp.y + dy[i] , cp.x + dx[i] };
			if (np.y < 0 || np.x < 0 || np.y >= h || np.x >= w)continue;
			if (visited[np.y][np.x] > 0) continue;
			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
			
			if (np.y == target.y && np.x == target.x) {
				cout << visited[np.y][np.x] -1;
				return;
			}
		}
	}
	
}

int main() {
	cin >> h >> w;
	

	cin >> knight.y >> knight.x >> target.y >> target.x;

	bfs({ knight.y, knight.x });
}
