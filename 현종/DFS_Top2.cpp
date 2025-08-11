#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, S;
vector<int> v[101];
vector<int> path;

int visited[101];
//1. 가지고 있는 것 중에 큰 걸로 넘어간다.

void preorder(int n) {
	visited[n] = 1; 
	cout << n << " ";
	if (v[n].empty())return;
	sort(v[n].rbegin(), v[n].rend());
	for (int i = 0; i < v[n].size(); i++)
	{
		if (visited[v[n][i]])continue;
		preorder(v[n][i]);
	}
}
void postorder(int n) {
	visited[n] = 1;
	if (v[n].empty())return;
	sort(v[n].rbegin(), v[n].rend());
	for (int i = 0; i < v[n].size(); i++)
	{
		if (visited[v[n][i]])continue;
		postorder(v[n][i]);
		cout << v[n][i]<<" ";
	}
}

int main() {
	cin >> N >> K >> S;
	for (int i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	preorder(S);
	memset(visited, 0, (N+1)*sizeof(int));
	cout << "\n";
	postorder(S);
	cout << S;
}
