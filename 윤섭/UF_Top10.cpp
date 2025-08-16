#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, M;
string cow;
vector<int> parent;

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
	cin >> N >> M;
	cin >> cow;
	cow = " " + cow;
	parent.assign(N + 5, 0);

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N - 1; i++) {
		int u, v;
		cin >> u >> v;
		if (cow[u] == cow[v]) setUnion(u, v);
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		if (find(a) == find(b)) {
			if (cow[a] == c) cout << 1;
			else cout << 0;
		}
		else {
			cout << 1;
		}
	}

}
