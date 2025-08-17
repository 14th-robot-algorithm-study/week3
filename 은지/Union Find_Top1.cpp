#include <iostream>
#include <vector>
using namespace std;

int N, Q;
int parent[1001];

int find(int tar) {
	if (tar == parent[tar]) {
		return tar;
	}

	int ret = find(parent[tar]);
	parent[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) {
		return;
	}

	parent[t2] = t1;
}

int main() {
	std::cin >> N >> Q;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < Q; i++) {
		int g, from, to;
		std::cin >> g >> from >> to;

		if (g == 1) {
			setUnion(from, to);
		}
		else {
			if (find(from) != find(to)) {
				std::cout << "NO" << "\n";
			}
			else {
				std::cout << "YES" << "\n";
			}
		}
	}


	return 0;
}
