#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

int N, en;
int cnt1, cnt2;
int parent[26];
int visited[26];

int find(int tar) {
	if (tar == parent[tar]) { 
		return tar;
	}

	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) {
		return;
	}

	if (t1 < t2) {
		parent[t2] = t1;
	}
	else {
		parent[t1] = t2;
	}

}

int main() {
	std::cin >> N;

	for (int i = 0; i < 26; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < N; i++) {
		char a, b;
		std::cin >> a >> b;

		a = a - 'A';
		b = b - 'A';
		en = b;

		setUnion(a, b);
		visited[a] = 1;
		visited[b] = 1;

	}

	// 참가자들만 대상으로 대표 모아서(유니크) 집합 개수
	set<int> roots;
	int participants = 0;

	for (int i = 0; i < 26; i++) {
		if (!visited[i]) {
			continue;
		}
		participants++;
		roots.insert(find(i));
	}

	std::cout << (int)roots.size() << '\n' << 26 - participants;
	return 0;
}
