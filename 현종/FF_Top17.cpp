#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Point {
	int y, x;
};
int N, M;
int arr[100][100];
int cost[100][100];
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };
vector<Point> v;
queue<Point> q; 
int visited[100][100];
int num;
void bfs(Point st, int num) {
	q.push(st);
	visited[st.y][st.x] = num;
	while (!q.empty()) {
		Point cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
				Point next = { cur.y + dy[i],cur.x + dx[i] };
			if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M)continue;
			if (visited[next.y][next.x])continue;
			if (arr[next.y][next.x]) {
				visited[next.y][next.x] = num;
				q.push(next);
			}
		}
	}
}
int search(Point cur) {
	int cnt = 0;
	for (int i = 0; i < 4; i++)
	{
		Point next = { cur.y + dy[i], cur.x + dx[i] };
		if (next.y < 0 || next.y >= N || next.x < 0 || next.x >= M)continue;
		if (!arr[next.y][next.x])cnt++;
	}
	return cnt;
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j])
				v.push_back({ i,j });
		}
	}
	int year = 0;
	int flag = 0;
	while (v.size()) {
		year++;
		memset(visited, 0, sizeof(visited));
		int erase_cnt = 0;
		for (int i = 0; i < v.size(); i++)
		{
			cost[v[i].y][v[i].x] = search(v[i]);
		}
		for (int i = 0; i < v.size();)
		{
			arr[v[i].y][v[i].x] -= cost[v[i].y][v[i].x];
			if (arr[v[i].y][v[i].x] <= 0) {
				arr[v[i].y][v[i].x] = 0;
				v.erase(v.begin() + i);
				erase_cnt++;
			}
			else
				i++;
		}

		if (erase_cnt) {	
			num = 1;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < M; j++)
				{
					if (arr[i][j] && !visited[i][j])
						bfs({ i,j },num++);
				}
			}
			if (num > 2)break;

		}

	}
	if (!v.size())
		cout << 0;
	else
		cout << year;


	return 0;

}
