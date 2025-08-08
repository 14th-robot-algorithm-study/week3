#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[101];
int visited[100];
int totalCnt = 0;

void func(int now) {
	visited[now] = 1;

	for (int i = 0; i < v[now].size(); i++) {
		if (visited[v[now][i]] == 0) {
			visited[v[now][i]] = 1;
			totalCnt++;
			func(v[now][i]);
		}
	}
}

int main() {

	cin >> nodeCnt >> edgeCnt;

	for (int i = 0; i < edgeCnt; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}

	visited[1] = 1;
	func(1);

	cout << totalCnt << '\n';
	return 0;
}
