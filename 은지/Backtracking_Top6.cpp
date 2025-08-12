#include <iostream>

int N;
int total_cnt;
int v1[13];
int v2[200];
int v3[200];

void dfs(int lev, int cnt) {
	if (cnt == N) {
		total_cnt++;
		return;
	}

	for (int i = 0; i < N; i++) {
		if (v1[i] == 1) {
			continue;
		}

		if (v2[lev + i] == 1) {
			continue;
		}

		if (v3[3 + (lev - i)] == 1) {
			continue;
		}

		
		v1[i] = 1;
		v2[lev + i] = 1;
		v3[3 + (lev - i)] = 1;
		dfs(lev + 1, cnt + 1);
		v1[i] = 0;
		v2[lev + i] = 0;
		v3[3 + (lev - i)] = 0;
	}
}


int main() {
	std::cin >> N;
	
	dfs(0, 0);
	std::cout << total_cnt;

	return 0;
}
