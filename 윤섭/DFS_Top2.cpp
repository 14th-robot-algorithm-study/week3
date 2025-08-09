#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int st;
vector<int> v[101];
int visited[101];
vector<int> postOrder;

void func(int now) {
	for (int i = 0; i < v[now].size(); i++) {
		if (visited[v[now][i]] == 1) continue;
		visited[v[now][i]] = 1;
		cout << v[now][i] << " ";
		func(v[now][i]);
	}

	postOrder.push_back(now);
}

int main() {
	cin >> N >> K;
	cin >> st;
	for (int i = 0; i < K; i++) {
		int from, to;
		cin >> from >> to;
		v[from].push_back(to);
	}
	
	for (int i = 0; i < K; i++) {
		sort(v[i].begin(), v[i].end(), greater<int>());
	}

	cout << st << " ";
	visited[st] = 1;
	func(st);
	cout << '\n';

	for (int i = 0; i < postOrder.size(); i++) {
		cout << postOrder[i] << ' ';
	}
}
