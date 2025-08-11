#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> arr;
vector<vector<bool>> visited;
vector<bool> desertEaten;
int max_cnt;

// 0: 하우, 1: 하좌, 2: 상좌, 3: 상우
int dy[4] = { 1, 1, -1, -1 };
int dx[4] = { 1, -1, -1, 1 };

void init() {
    arr.clear();
    arr.resize(n, vector<int>(n));
    visited.clear();
    visited.resize(n, vector<bool>(n, false));
    desertEaten.assign(101, false);
    max_cnt = -1;  // 불가능한 경우 -1 출력
}

void input() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}

void dfs(int y, int x, int startY, int startX, int count, int dir) {
    for (int i = dir; i <= dir + 1 && i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        // 범위 밖
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;

        // 시작점으로 돌아왔고, 최소 4개 이상이면 경로 완성
        if (ny == startY && nx == startX && count >= 4) {
            max_cnt = max(max_cnt, count);
            return;
        }

        // 이미 방문했거나 디저트 중복이면 패스
        if (visited[ny][nx] || desertEaten[arr[ny][nx]]) continue;

        visited[ny][nx] = true;
        desertEaten[arr[ny][nx]] = true;

        dfs(ny, nx, startY, startX, count + 1, i);

        visited[ny][nx] = false;
        desertEaten[arr[ny][nx]] = false;
    }
}

int main() {
    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> n;
        init();
        input();

        max_cnt = -1;

        // 모든 위치에서 탐색 시작
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                visited[i][j] = true;
                desertEaten[arr[i][j]] = true;
                dfs(i, j, i, j, 1, 0);  // 방향 0부터 시작
                visited[i][j] = false;
                desertEaten[arr[i][j]] = false;
            }
        }

        cout << "#" << tc << " " << max_cnt << "\n";
    }

    return 0;
}
