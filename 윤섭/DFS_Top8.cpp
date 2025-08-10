#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge {
	int to;
	int distance;
};

int N, R1, R2;	// 방의 개수, 두 로봇의 각 위치	(R1과 R2를 각각 st, en으로 생각해도 됨)
vector<Edge> v[100001];
int visited[100001];
int minDistanceSum = 21e8;	//가장 작은 거리의 합

void func(int now, int distance, int maxDistance) {	//maxDistance는 경로 중 가장 큰 거리
	if (now == R2) {
		minDistanceSum = min(minDistanceSum, distance-maxDistance);
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int to = v[now][i].to;
		if (visited[to] == 1) continue;
		visited[to] = 1;
		func(to, distance + v[now][i].distance, max(maxDistance, v[now][i].distance));
		visited[to] = 0;
	}
}

int main() {
	cin >> N >> R1 >> R2;
	
	for (int i = 0; i < N-1; i++) {
		int from, to, distance;
		cin >> from >> to >> distance;
		v[from].push_back({ to, distance });
		v[to].push_back({ from, distance });

	}

	visited[R1] = 1;
	func(R1, 0, 0);
	cout << minDistanceSum;
	return 0;
}
