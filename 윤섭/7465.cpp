/* union find */
#include <iostream>
#include <cstring>
using namespace std;

int T;
int N, M;
int group_cnt;
int parent[101];

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
	return;
}

int main() {
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		group_cnt = 0;
		
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < M; i++) {
			int from, to;
			cin >> from >> to;
			setUnion(from, to);
		}

		for (int i = 1; i <= N; i++) {
			if (parent[i] == i) group_cnt++;
		}

		cout << "#" << tc << " " << group_cnt << "\n";
	}
}

/* BFS */
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int T;
int N, M;
int group_cnt;
vector<vector<int>> v;
int visited[101];

void bfs(int st) {
	visited[st] = 1;
	group_cnt++;
	queue <int> q;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] == 1) continue;

			visited[next] = 1;
			q.push(next);
		}
	}
}

int main() {
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++) {
		group_cnt = 0;
		
		cin >> N >> M;
		v.assign(N + 1, vector<int>());
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < M; i++) {
			int from, to;
			cin >> from >> to;
			v[from].push_back(to);
			v[to].push_back(from);

		}
		
		for (int i = 1; i <= N; i++) {
			if (visited[i] == 0) {
				bfs(i);
			}
		}

		cout << "#" << tc << " " << group_cnt << "\n";
	}
}
