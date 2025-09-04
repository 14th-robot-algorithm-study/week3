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
