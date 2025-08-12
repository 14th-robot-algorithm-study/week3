#include <iostream>

int N, M;
int pick[10];
int visited[10];


void M1(int lev) {

	if (lev == N) {
		for (int i = 0; i < 10; i++) {
			if (pick[i]) {
				std::cout << pick[i] << " ";
			}
		}

		std::cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) {
		pick[lev] = i;
		M1(lev + 1);
	}
}


void M2(int lev, int idx) {

	if (lev == N) {
		for (int i = 0; i < 10; i++) {
			if (pick[i]) {
				std::cout << pick[i] << " ";
			}
		}

		std::cout << "\n";
		return;
	}

	for (int i = idx; i <= 6; i++) {
		pick[lev] = i;
		M2(lev + 1, i);
	}
}


void M3(int lev) {

	if (lev == N) {
		for (int i = 0; i < 10; i++) {
			if (pick[i]) {
				std::cout << pick[i] << " ";
			}
		}

		std::cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) {
		if (visited[i] == 1) {
			continue;
		}

		visited[i] = 1;
		pick[lev]  = i;
		M3(lev + 1);
		visited[i] = 0;
	}
}


int main() {
	std::cin >> N >> M;

	switch (M) {
	case 1:
		M1(0);
		break;
	case 2:
		M2(0, 1);
		break;
	case 3:
		M3(0);
		break;
	default:
		break;
	}


	return 0;
}
