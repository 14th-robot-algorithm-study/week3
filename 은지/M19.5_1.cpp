#include <iostream>
#include <algorithm>

void BBQ(int& a, int& b) {
	int max_val = -21e8;
	int min_val = 21e8;
	int arr[5];
	for (int i = 0; i < 5; i++) {
		std::cin >> arr[i];
	}

	for (int i = 0; i < 5; i++) {
		max_val = std::max(max_val, arr[i]);
		min_val = std::min(min_val, arr[i]);
	}

	a = max_val;
	b = min_val;
}


int main() {
	int a, b;
	BBQ(a, b);

	std::cout << "a=" << a << "\n";
	std::cout << "b=" << b << "\n";

	return 0;
}
