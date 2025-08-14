#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, K, S;
std::vector<int> v[101];
int visited[101];

bool compare(int a, int b) {
	return a > b;
}

void preorder(int now) {
	if (v[now].size() == 0) {
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next] == 1) {
			continue;
		}

		if (next != S) {
			std::cout << next << " ";
		}

		visited[next] = 1;
		preorder(next);
	}
}


void postorder(int now) {
	if (v[now].size() == 0) {
		return;
	}

	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i];
		if (visited[next] == 1) {
			continue;
		}

		visited[next] = 1;
		postorder(next);
		if (next != S) {
			std::cout << next << " ";
		}
	}
}


int main() {
	std::cin >> N >> K >> S;

	for (int i = 0; i < K; i++) {
		int from, to;
		std::cin >> from >> to;
		v[from].push_back(to);
	}

	for (int i = 0; i < N; i++) {
		std::sort(v[i].begin(), v[i].end(), compare);
	}

	std::cout << S << " ";
	preorder(S);
	memset(visited, 1, sizeof(visited));

	std::cout << "\n";
	visited[S] = 1;
	postorder(S);
	std::cout << S << " ";

	return 0;
}
