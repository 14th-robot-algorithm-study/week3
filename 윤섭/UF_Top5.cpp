#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int width, N;
vector <int> v;
vector <int> parent;
vector <int> house;

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
	house[t1] += house[t2];
	return;
}

int main() {
	cin >> width >> N;
	v.resize(width + 5);
	parent .resize(width + 5);
	house.resize(width + 5);

	for (int i = 0; i < width; i++) {
		parent[i] = i;
	}
	
	for (int i = 0; i < N; i++) {
		int houseCnt = 0;
		int maxHouse = 0;
		int place;
		cin >> place;
		v[place] = 1;
		house[place] = 1;

		for (int j = 0; j < width; j++) {
			if (v[j] == 1 && v[j + 1] == 1) {
				setUnion(j, j + 1);
			}
		}

		for (int j = 0; j < width; j++) {
			if (v[j] == 1 && j == find(j)) {
				houseCnt++;
				maxHouse = max(maxHouse, house[j]);
			}
		}


		cout << houseCnt << " " << maxHouse << "\n";
	}

	
}
