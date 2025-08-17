#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, T, coco, her;
int visited[101];
vector <int> v[101];

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
				continue;;
			}

			visited[next] = 1;
			q.push(next);
		}
	}

	if (visited[st] == 1 && visited[her] == 1) {
		std::cout << "YES";
	}
	else {
		std::cout << "NO";
	}
}

int main() {
	std::cin >> N >> T;

	for (int i = 0; i < T; i++) {
		int from, to;
		std::cin >> from >> to;

		v[from].push_back(to);
		v[to].push_back(from);
	}

	std::cin >> coco >> her;

	bfs(coco);

	return 0;
}
