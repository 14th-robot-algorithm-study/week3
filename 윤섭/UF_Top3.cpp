#include <iostream>
#include <vector>
using namespace std;

int N;
int parent[26]; 
int cnt;
int sol;
int solVisited[26];

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;

}

int main() {
	cin >> N;
	for (int i = 0; i < 26;i++) parent[i] = i;

	for (int i = 0; i < N; i++) {
		char from, to;
		cin >> from >> to;

		int a = from - 'A';
		int b = to - 'A';

		setUnion(a, b);

		if (solVisited[a] == 0) {
			solVisited[a] = 1;
			sol++;
		}
		if (solVisited[b] == 0) {
			solVisited[b] = 1;
			sol++;
		}
	}

	for (int i = 0; i < 26; i++) {
		if(parent[i] == i)
		cnt++;
	}

	cout << cnt-26+sol << "\n" << 26-sol;
}
