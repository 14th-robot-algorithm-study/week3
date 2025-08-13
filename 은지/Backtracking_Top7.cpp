#include <iostream>
#include <string>
using namespace std;

int N;
int val;
int res;
std::string str;
int arr[101];
int visited[101];


void dfs(int lev, std::string str) {
	if (lev == N) {
		if (res != 0 && res % 101 == 0) {
			std::cout << str << "\n";
		}
		return;
	}


	if (lev == 0) {
		res = arr[lev];
		dfs(lev + 1, to_string(arr[lev]));
		return;
	}


	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			int tmp = res;
			res *= arr[lev];
			dfs(lev + 1, str + "*" + to_string(arr[lev]));
			res = tmp;
		}

		if (i == 1) {
			res += arr[lev];
			dfs(lev + 1, str + "+" + to_string(arr[lev]));
			res -= arr[lev];
		}

		if (i == 2) {
			res -= arr[lev];
			dfs(lev + 1, str + "-" + to_string(arr[lev]));
			res += arr[lev];
		}



	}

}


int main() {
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	dfs(0, str);

	return 0;;
}
