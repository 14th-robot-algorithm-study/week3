#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Point {
	int y, x;
};

int dy[4] = { -1, 1, 1, -1 };	
int dx[4] = { 1, 1, -1, -1 };
int N;
int map[20][20];
int visited[101];
int totalCnt;

void func(Point st, int dir, Point target, int cnt, int dirCnt) {
	if (st.y == target.y && st.x == target.x && dirCnt == 3) {
		totalCnt = max(totalCnt, cnt);
		return;
	}

	if (dirCnt >= 4) return;

	for (int i = 0; i < 2; i++) {
		int ndir = (dir + i) % 4; 
		Point ny = { st.y + dy[ndir], st.x + dx[ndir] };

		if (ny.y < 0 || ny.x < 0 || ny.y >= N || ny.x >= N) continue;
		if (visited[map[ny.y][ny.x]] == 1) continue;

		visited[map[ny.y][ny.x]] = 1;
		func(ny, ndir, target, cnt + 1, dirCnt + i);
		visited[map[ny.y][ny.x]] = 0;
	}
}

int main() {

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		totalCnt = -1;
		memset(visited, 0, sizeof(visited));
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				func({ i, j }, 2, { i,j }, 0, 0);
			}
		}

		cout << "#" << tc << " " << totalCnt << "\n";
	}

}
