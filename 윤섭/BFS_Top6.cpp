#include <iostream>
#include <queue>

using namespace std;

int N, T;
vector<int> v[100];
int A, B;
int flag;
int visited[100];

void bfs(int st) {
	queue <int> q;
	q.push(st);
	
	while (!q.empty()) {
		int cur = q.front();
		visited[cur] = 1;
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] == 1) continue;
			visited[next] = 1;
			q.push(next);
			if (next == B) {
				flag = 1;
				return;
			}
		}
	}
}

int main() {
	cin >> N >> T;
	for (int i = 0; i < T; i++) {
		int from, to;
		cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	cin >> A >> B;
	
	bfs(A);

	if (flag == 0) cout << "NO";
	else if (flag == 1) cout << "YES";
}
