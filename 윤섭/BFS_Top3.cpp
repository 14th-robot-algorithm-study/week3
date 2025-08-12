#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, stUser, cnt;
vector<int> v[100001];
int visited[100001];

void bfs(int st) {
	queue<int> q;
	visited[st] = 1;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next]) continue;
			visited[next] = 1;
			cnt++; 
			q.push(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	cin >> stUser;
	bfs(stUser);

	cout << cnt;
}
