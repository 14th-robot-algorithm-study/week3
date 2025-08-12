#include <iostream>
#include <queue>
using namespace std;

struct Point {
	int y, x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[5][5];

void func(Point st) {
	queue <Point> q;
	visited[st.y][st.x] = 1;
	q.push(st);

	while (!q.empty()) {
		Point cp = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			Point np = { cp.y + dy[i], cp.x + dx[i] };
			if (np.y < 0 || np.x < 0 || np.y >= 5 || np.x >= 5)
				continue;
			if (visited[np.y][np.x] > 0) continue;

			visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
			q.push(np);
		}
	}
}

int main() {
	int stY, stX;
	cin >> stY >> stX;

	func({ stY, stX });

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}
}
