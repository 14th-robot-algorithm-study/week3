#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int visited[31];
vector<int> node[31];
int adapter[31][2];

void func(int now) {
	adapter[now][0] = 0;	// 얼리 어댑터가 아닐 때
	adapter[now][1] = 1;	// 얼리 어댑터 일 때

	for (int i = 0; i < node[now].size(); i++) {
		int next = node[now][i];
		if (visited[next] == 1) continue;
		visited[next] = 1;
		func(next);

		adapter[now][0] += adapter[next][1];	// 얼리 어댑터가 아닐 때 다음 자식 노드는 무조건 얼리 어댑터
		adapter[now][1] += min(adapter[next][1], adapter[next][0]);	// 얼리 어댑터 일 때는 자식 노드가 얼리 어댑터일 수도 있고 아닐 수도 있음

	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v;
		cin >> u >> v;
		node[u].push_back(v);
		node[v].push_back(u);
	}
	visited[1] = 1;
	func(1);

	cout << min(adapter[1][0], adapter[1][1]);
}
