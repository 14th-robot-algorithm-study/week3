#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int T;
int visited[11];
vector <int> v[11];

void bfs(int st) {
	queue<int> q;
	q.push(st);
	

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] > 0) continue;
			if (next == T) continue;
			visited[next] = visited[cur] + 1;
			q.push(next);

			if (next == N) {
				cout << visited[next] - 1;
				return;
			}
		}
	}

	cout << "-1";
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		v[A].push_back(B);
		v[B].push_back(A);
	}
	cin >> T;
	visited[1] = 1;
	bfs(1);
}
