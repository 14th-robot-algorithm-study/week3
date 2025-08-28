#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Point {
	int y, x;
};

struct Cell {
	int y, x;
	int life;
	int alive_time;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int T;
int N, M, K;
int map[350][350];
vector <Cell> cell;
int ans;

struct cmp
{
	bool operator()(Cell a, Cell b)
	{
		return a.life < b.life;
	}
};

void bfs() {
	priority_queue <Cell, vector<Cell>, cmp> pq;
	int dead = 0;
	for (int t = 1; t <= K; t++) {
		/*     셀 활성화     */
		for (int i = 0; i < cell.size(); i++) {
			cell[i].alive_time--;
			if (cell[i].alive_time == -1) {
				pq.push(cell[i]);
			}
			if (cell[i].alive_time == -cell[i].life) {
				dead++;
			}
		}
		/*     셀 활성화     */

		/*     줄기 세포 배양     */
		while (!pq.empty()) {
			Cell cp = pq.top();
			pq.pop();

			for (int dir = 0; dir < 4; dir++) {
				Cell np = { cp.y + dy[dir], cp.x + dx[dir], cp.life, cp.life };
				if (map[np.y][np.x] != 0) continue;
				map[np.y][np.x] = np.life;
				cell.push_back(np);
			}
		}
		/*     줄기 세포 배양     */
		
	}
	ans = cell.size() - dead;
}

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		/*     초기화     */
		ans = 0;
		memset(map, 0, sizeof(map));
		cell.clear();
		/*     초기화     */
		
		/*     입력     */
		cin >> N >> M >> K;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[150 + i][150 + j];
				if (map[150 + i][150 + j] != 0) {
					cell.push_back({ 150 + i, 150 + j, map[150 + i][150 + j], map[150 + i][150 + j] });
				}
			}
		}
		/*     입력     */

		/*     시뮬레이션     */
		bfs();
		/*     시뮬레이션     */


		cout << "#" << tc << " " << ans << "\n";
	}
}
