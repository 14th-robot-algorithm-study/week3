#include <iostream>
#include <vector>
using namespace std;

struct Point {
	int x, y, R;
};
vector<int> parent;
vector<Point> top;

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
	return;
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int N;
		cin >> N;
		
		parent.assign(N, 0);
		top.assign(N, { 0,0,0 });
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			parent[i] = i;
		}

		for (int i = 0; i < N; i++) {
			cin >> top[i].x >> top[i].y >> top[i].R;
		}

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (((top[i].x - top[j].x) * (top[i].x - top[j].x)) + ((top[i].y - top[j].y) * (top[i].y - top[j].y)) <= (top[i].R + top[j].R)* (top[i].R + top[j].R)) {
					setUnion(i, j);
				}
			}
		}

		for (int i = 0; i < N; i++) {
			if (parent[i] == i) cnt++;
		}
		cout << cnt << "\n";
	}

}
