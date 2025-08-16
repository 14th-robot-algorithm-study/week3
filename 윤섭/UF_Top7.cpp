#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
int N;
vector<int> parent;
vector<int> car;
int cnt;

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
	cin >> T;
	cin >> N;
	parent.resize(T + 1);
	car.resize(N + 1);

	for (int i = 0; i <= T; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		cin >> car[i];
	}

	for (int i = 0; i < N; i++) {
		int t = find(car[i]);
		if (t == 0) break;
		setUnion(t - 1, t);	
		cnt++;
	}

	cout << cnt;

}
