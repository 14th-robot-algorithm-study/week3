#include <iostream>

int N, cnt;
int visited[100];

void func(int val) {
	if (val > N) {
		return;
	}

	if (val == N) {
		cnt++;
		return;
	}

	for (int i = 1; i < 4; i++) {
		func(val + i);
	}

}


int main() {
	std::cin >> N;

	func(0);
	std::cout << cnt;

	return 0;
}
