#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
int arr[12][12];
int minCost = 21e8;
int visited[12];

void func(int now, int cost, int cnt) {
	if (cnt == N-1) {
		if (arr[now][0] == 0) return;
		cost += arr[now][0];
		minCost = min(minCost, cost);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i] == 1) continue;
		if (arr[now][i] == 0) continue;
		visited[i] = 1;
		func(i, cost + arr[now][i], cnt + 1);
		visited[i] = 0;
	}
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	visited[0] = 1;
	func(0, 0, 0);
	
	cout << minCost;
}
