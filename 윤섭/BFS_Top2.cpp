#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair <int, int>> v[10];
int N, M, K;
vector <int> enter;
int visited[10];
int coin[10];

void bfs(int st) {
	visited[st] = 1;
	queue <int> q;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].first;
			if (visited[next] == 1)continue;
			visited[next] = 1;
			coin[next] = coin[cur] + v[cur][i].second;
			if (coin[next] <= K) {
				enter.push_back(next);
			}
			q.push(next);
		}
	}
}

int main() {
	cin >> N >> M >> K;
	
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		v[A].push_back({ B, C });
		v[B].push_back({ A, C });
	}

	bfs(0);

	sort(enter.begin(), enter.end());

	for (int i = 0; i < enter.size(); i++) {
		cout << enter[i] << " ";
	}
}

