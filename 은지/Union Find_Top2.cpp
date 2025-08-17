#include <iostream>

int N;
int arr[1001][1001];
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
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> arr[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (arr[i][j] == 0) {
				continue;
			}

			if (find(i) == find(j)) {
				std::cout << "WARNING";
				return 0;
			}
			setUnion(i, j);
		}
	}
	std::cout << "STABLE";

	return 0;
}
