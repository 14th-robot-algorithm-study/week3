#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int map[1000][1000];
int parent[1000];
int flag;

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void unite(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) {
		flag = 1;
		return;
	}
	parent[t2] = t1;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (map[i][j] == 0) continue;
			unite(i, j);
			if (flag == 1) break;
		}
		if (flag == 1) break;

	}
	if (flag == 1) cout << "WARNING";
	else cout << "STABLE";
}
