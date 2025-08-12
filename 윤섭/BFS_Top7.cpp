#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int R, K;	
vector<int> v[11];
int cnt;
int visited[11];

void bfs(int st) {
	queue<int> q;
	visited[st] = 1;
	cnt++;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] > 0) continue;
			visited[next] = visited[cur] + 1;
			if (visited[next] >= 1 && visited[next] <= K + 1) cnt++;
			q.push(next);

		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	cin >> R >> K;

	bfs(R);
	cout << cnt;
}
