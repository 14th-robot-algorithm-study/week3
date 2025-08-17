// [방법 1] ==================================================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, S, cnt;
int visited[100'001];
vector <int> v[100'001];

void bfs(int st) {
	queue <int> q;
	visited[st] = 1;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];

			if (visited[next]) {
				continue;
			}

			visited[next] = 1;
			q.push(next);
		}
	}

	for (int i = 0; i < N + 1; i++) {
		if (i == S || visited[i] == 0) {
			continue;
		}
		cnt++;
	}
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		std::cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	std::cin >> S;

	bfs(S);
	std::cout << cnt;

	return 0;
}
// ===========================================================


// [방법 2] ==================================================
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, st, cnt;
vector<int> v[100'001];
int visited[100'001];


void bfs(int now) {
	queue <int> q;
	visited[now] = 1;
	q.push(now);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			if (visited[v[cur][i]] == 1) {
				continue;
			}

			visited[v[cur][i]] = 1;
			q.push(v[cur][i]);
			cnt++;
		}
	}

}



int main() {
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int from, to;
		std::cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	std::cin >> st;

	bfs(st);

	std::cout << cnt;

	return 0;
}
// ===========================================================
