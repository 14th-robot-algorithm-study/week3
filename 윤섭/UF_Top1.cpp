#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector <int> parent;
int N, Q;
vector <vector<int>> v;

int find(int t) {
	if (t == parent[t]) return t;
	return parent[t] = find(parent[t]);
}

void unite(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) return;
	parent[t2] = t1;
}

int main() {
	cin >> N >> Q;

	parent.resize(N + 1);
	v.resize(N + 1);

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < Q; i++) {
		int mode, from, to;
		cin >> mode >> from >> to;

		if (mode == 0) {
			if (find(from) == find(to)) cout << "YES\n";
			else if (find(from) != find(to)) cout << "NO\n";
		}
		
		else if (mode == 1) {
			v[from].push_back(to);
			v[to].push_back(from);

			unite(from, to);
		}
		

	}
}
