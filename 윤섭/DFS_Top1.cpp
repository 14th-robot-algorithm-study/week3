#include <iostream>
#include <vector>
using namespace std;

int nodeCnt, edgeCnt;
vector<int> v[101];
int visited[101]; 
int totalCnt = 0;

void func(int now) {
	visited[now] = 1;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next] == 0) {
			totalCnt++;       
			func(next);       
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

	func(1);  

	cout << totalCnt << '\n';
	return 0;
}
