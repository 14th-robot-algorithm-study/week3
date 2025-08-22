#include <iostream>
#include <string>
using namespace std;

int N, cnt;
string str[101];
int visited[101];

void dfs(int lev, string text) {
	if (lev == 4){
		if (text == "CHRISTMAS") {
			cnt++;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			continue;
		}

		visited[i] = 1;
		dfs(lev + 1, text + str[i]);
		visited[i] = 0;
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> str[i];
	}

	dfs(0, "");
	std::cout << cnt;

	return 0;
}
