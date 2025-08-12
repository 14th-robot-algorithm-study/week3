#define _CRT_SECIRE_NO_WARNiNGS
#include <iostream>
#include <algorithm>
using namespace std;

int T, N, rst;
int map[100][100];

struct Point {
	int y;
	int x;
};


// [1] 웜홀 정보 
Point wormhole[11][2];


// [2] 시작점
Point sp;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };


// [3] [함수] 입력
void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

}


// [4] [함수] wormhole 초기화
void initWormhole() {
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 2; j++) {
			wormhole[i][j].y = -1;
			wormhole[i][j].x = -1;
		}
	}
}


// [5] [함수] wormhole 저장
void findWormhole() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] >= 6 && map[i][j] <= 10) {
				int wormholeNum = map[i][j];

				if (wormhole[wormholeNum][0].y == -1) {
					wormhole[wormholeNum][0].y = i;
					wormhole[wormholeNum][0].x = j;
				}

				else {
					wormhole[wormholeNum][1].y = i;
					wormhole[wormholeNum][1].x = j;
				}
			}
		}
	}
}


// [6] [함수] 방향 찾기
int findDirection(int num, int d) {
	int directions[5][4] = {
		// 1번 도형
		// 상 하 좌 우 
		{1, 3, 0, 2},
		{3, 0, 1, 2},
		{2, 0, 3, 1},
		{1, 2, 3, 0},
		{1, 0, 3, 2}
	};

	return directions[num - 1][d];
}


// [7] [함수] simulation
void simulation(Point cp, int d) {
	int cnt = 0;

	while (true) {
		cp.y += dy[d];
		cp.x += dx[d];

		// 벽 
		if (cp.y < 0 || cp.y >= N || cp.x < 0 || cp.x >= N) {
			cnt++;
			d = findDirection(5, d);
			continue;
		}

		// 시작점 또는 블랙홀
		if (cp.y == sp.y && cp.x == sp.x || map[cp.y][cp.x] == -1) {
			rst = max(cnt, rst);
			return;
		}

		// 빈 공간
		if (map[cp.y][cp.x] == 0) {
			continue;
		}

		// 블럭
		if (map[cp.y][cp.x] >= 1 && map[cp.y][cp.x] <= 5) {
			cnt++;
			d = findDirection(map[cp.y][cp.x], d);
		}

		// 웜홀
		if (map[cp.y][cp.x] >= 6 && map[cp.y][cp.x] <= 10) {
			int targetWormholeNum = map[cp.y][cp.x];

			if (wormhole[targetWormholeNum][0].y == cp.y && wormhole[targetWormholeNum][0].x == cp.x) {
				cp.y = wormhole[targetWormholeNum][1].y;
				cp.x = wormhole[targetWormholeNum][1].x;
			}

			else {
				cp.y = wormhole[targetWormholeNum][0].y;
				cp.x = wormhole[targetWormholeNum][0].x;
			}
		}
	}
}


// [8] [함수] 각 지점마다 이동
void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int d = 0; d < 4; d++) {
				if (map[i][j] == 0) {
					sp.y = i;
					sp.x = j;
					simulation(sp, d);
				}
			}
		}
	}
}


// [9] [함수] main
int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		input();
		rst = 0;
		initWormhole();
		findWormhole();
		solve();
		cout << "#" << tc << " " << rst << '\n';
	}

	return 0;
}
