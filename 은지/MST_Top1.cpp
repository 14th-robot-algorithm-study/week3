#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
	int a;
	int b;
	int cost;
};

int nodeCnt, edgeCnt;
int parent[10'001];
vector <Edge> v;

bool compare(Edge a, Edge b) {
	return a.cost < b.cost;
}

void init() {
	for (int i = 0; i < edgeCnt; i++) {
		parent[i] = i;
	}
}

int find(int tar) {
	if (tar == parent[tar]) {
		return tar;
	}

	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) {
		return;
	}

	parent[t2] = t1;
}

int kruskal() {
	int result = 0;
	int selectCnt = 0; 

	for (Edge sel : v) {
		int a = sel.a;
		int b = sel.b;
		int cost = sel.cost;

		if (find(a) == find(b)) {
			continue;
		}

		setUnion(a, b);
		result += cost;
		selectCnt++;

		if (selectCnt == nodeCnt - 1) {
			break;
		}
	}

	return result;
}

int main() {
	std::cin >> nodeCnt >> edgeCnt;
	
	for (int i = 0; i < edgeCnt; i++) {
		int a, b, cost;
		std::cin >> a >> b >> cost;

		v.push_back({ a, b, cost });
	}

	init();
	sort(v.begin(), v.end(), compare);

	int result = kruskal();

	std::cout << result << '\n';

	return 0;
}
