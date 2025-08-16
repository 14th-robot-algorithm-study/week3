#include <iostream>
#include <algorithm>
using namespace std;

int map[100][100];
int parent[10000];
int sizeofIsland[10000];
int N;
int sumTotalIsland;
int sumMaxIsland;
int totalIsland;
int maxIsland =1;

struct Point {
	int y, x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
	sizeofIsland[t1] += sizeofIsland[t2];
	totalIsland--;

	maxIsland = max(maxIsland, sizeofIsland[t1]);
}

int main() {
	cin >> N;

	for (int i = 0; i < 10000; i++) {
		parent[i] = i;
		sizeofIsland[i] = 1;
	}

	for (int i = 0; i < N; i++) {
		int cnt = 0;
		
		Point cp;
		cin >> cp.y >> cp.x;
		map[cp.y][cp.x] = 1;

		totalIsland++;

		for (int j = 0; j < 4; j++) {
			Point np = { cp.y + dy[j], cp.x + dx[j] };
			if (np.y < 0 || np.x < 0 || np.y >= 100 || np.x >= 100) continue;
			if (map[np.y][np.x] == 1) {
				setUnion(100 * cp.y + cp.x, 100 * np.y + np.x);
			}
		}
		
		sumTotalIsland += totalIsland;
		sumMaxIsland += maxIsland;
	}

	cout << sumTotalIsland << "\n";
	cout << sumMaxIsland;

}
