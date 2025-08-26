#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int T, N, M, C;
int map[10][10];
int square_map[10][10];
int visited[10][10];
int ans;
int best; 


void dfsSubset(int idx, int sum, int profit, int arr[]) {
	if (sum > C) return;              
	if (idx == M) {                
		best = max(best, profit);       
		return;
	}

	dfsSubset(idx + 1, sum + arr[idx], profit + arr[idx] * arr[idx], arr);
	dfsSubset(idx + 1, sum, profit, arr);
}

int getMaxProfit(int y, int x) {
	int arr[6];
	for (int i = 0; i < M; i++) arr[i] = map[y][x + i];

	best = 0;
	dfsSubset(0, 0, 0, arr);
	return best;
}

void dfs(int lev, int y, int x, int profit) {
	if (lev == 2) {
		ans = max(ans, profit);
		return;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= N - M; j++) {
			if (visited[i][j] == 1) continue;
			int flag = 0;

			for (int k = 0; k < M; k++) {
				if (visited[i][j + k] == 1) {
					flag = 1;
					break;
				}
			}

			if (flag == 0) {
				for (int k = 0; k < M; k++) visited[i][j + k] = 1;
				int addProfit = getMaxProfit(i, j);
				dfs(lev + 1, i, j, profit + addProfit);
				for (int k = 0; k < M; k++) visited[i][j + k] = 0;
			}
		}
	}
}


int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(map, 0, sizeof(map));
		memset(square_map, 0, sizeof(square_map));
		memset(visited, 0, sizeof(visited));
		ans = -21e8;

		cin >> N >> M >> C;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				square_map[i][j] = map[i][j] * map[i][j];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= N - M; j++) {

				for (int k = 0; k < M; k++) visited[i][j + k] = 1;
				
				int addProfit = getMaxProfit(i, j);
				dfs(1, i, j, addProfit);

				for (int k = 0; k < M; k++) visited[i][j + k] = 0;
			}
		}
		cout << "#" << tc << " " << ans << "\n";
	}
}
