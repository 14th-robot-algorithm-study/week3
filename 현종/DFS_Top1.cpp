#include <iostream>
using namespace std;

int arr[101][101];
int N, M;
int cnt;
int visited[101];
bool flag = false; 
void func(int cur) {
	visited[cur] = true;
	cnt++;
	for (int i = 1; i <= N; i++)
	{
		if (arr[cur][i] && !visited[i]) {

			func(i);
		}
	}
}
int main() {
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	func(1);
	cout << cnt - 1;
}
