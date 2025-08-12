#include <iostream>

int max_val;

int Collatz(int num, int count) {
	if (num == 1) {
		max_val = count;
		return 0;
	}
	
	if (num % 2 == 0) {
		return Collatz(num / 2, count + 1);
	}
	else {
		return Collatz((num * 3) + 1, count + 1);
	}

}

int main() {
	int N;
	std::cin >> N;
	Collatz(N, 0);
	std::cout << max_val;

}
