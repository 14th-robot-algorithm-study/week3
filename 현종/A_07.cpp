#include <iostream>	
#include <vector>
#include <queue>

using namespace std;

struct Point {
	int y, x;
};

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

queue<Point> q;
int N, M;

int flag;
void bfs(Point st, Point end, vector<vector<int>> arr, vector<vector<int>> visited) {
	q.push(st);
	visited[st.y][st.x] = 1;
	while (!q.empty()) {
		Point cur = q.front();
		if (cur.y == end.y && cur.x == end.x) {
			flag = 1;
			break;
		}
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			Point n = { cur.y + dy[i],cur.x + dx[i] };
			if (n.y < 0 || n.y >= N || n.x < 0 || n.x >= M)continue;
			if (visited[n.y][n.x])continue;
			if (!arr[n.y][n.x])continue;
			visited[n.y][n.x] = 1;
			q.push({ n.y,n.x });

			/*for (int l = 0; l < N; l++)
			{
				for (int m = 0; m < M; m++)
				{
					cout << visited[l][m] << " ";
				}
				cout << "\n";
			}
			cout << "\n";*/
		}
	}
}

int main() {
	Point end;
	cin >> N >> M;
	vector<vector<int>> arr(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 3)
				end = { i,j };
		}
	}
	int cnt = 1;
	while (1) {
		vector<vector<int>> visited(N, vector<int>(M, 0));
		//1 사이의 0 채우는 로직
		if (cnt > 1) {
			for (int i = 0; i < M; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (arr[j][i]) {
						int c = 1;
						while (1) {
							if (j + c >= N)break;
							if (!arr[j + c][i])
								c++;
							else if (c == cnt && arr[j + c][i]) {
								for (int k = 0; k < c; k++)
								{
									if (j + k + 1 == end.y && i == end.x)continue;
									arr[j + k + 1][i] = 1;
								}
								break;
							}
							else if (c > cnt - 1)break;
							else break;
						}
					}

					/*for (int l = 0; l < N; l++)
					{
						for (int m = 0; m < M; m++)
						{
							cout << arr[l][m] << " ";
						}
						cout << "\n";
					}
					cout << "\n";*/
				}
			}
		}

		bfs({ N - 1,0 }, end, arr, visited);
		if (flag)break;
		cnt++;

	}

	cout << cnt;
}