#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int st, en;
int visited[1000];
int maxCost = -1;
int minCost = 21e6;
vector<vector<int>> v;

void func(int now, int cost) {
	if (now == en) {
		maxCost = max(maxCost, cost);
		minCost = min(minCost, cost);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (v[now][i] == 0) continue;
		if (visited[i] == 1) continue;

		visited[i] = 1;
		func(i, cost + v[now][i]);
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> v[i][j];
		}
	}

	cin >> st >> en;
	visited[st] = 1;
	func(st, 0);
	cout << minCost << "\n"
		<< maxCost;
}
