#include <iostream>
#include <queue>
using namespace std;

int N;
int map[10][10];
int visited[10];

void func(int st) {
	queue<int> q;
	visited[st] = 1;
	q.push(st);
	cout << st << " ";

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++) {
			if (visited[i] == 1) continue;
			if (map[cur][i] == 0) continue;
			cout << i << " ";
			visited[i] = 1;
			q.push(i);
		}
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	func(0);
}
