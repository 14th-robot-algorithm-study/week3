#include <iostream>
#include <vector>
using namespace std;

int N, Pair;
int total_cnt;
int from, to;
std::vector <int> v[101];
int visited[101];

void func(int lev) {
	if (visited[lev] == 1) {
		return;
	}

	visited[lev] = 1;
	total_cnt++;
	for (int i = 0; i < v[lev].size(); i++) {
		func(v[lev][i]);
	}
}

int main() {
	std::cin >> N >> Pair;

	for (int i = 0; i < Pair; i++) {
		std::cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}


	func(1);
	std::cout << total_cnt - 1;

	return 0;
}
