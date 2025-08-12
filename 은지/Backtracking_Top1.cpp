#include <iostream>
#include <string>
#include <vector>

using namespace std;

int arr[100] = {};
std::string str;

int sum_val(int i) {
	if (i == str.size()) {
		return 0;
	}

	return (arr[i] + sum_val(i + 1));
}

int main() {	
	std::cin >> str;
	
	int idx = 0;
	for (char x : str) {
		arr[idx] = x - '0';
		idx++;
	}

	std::cout << sum_val(0);

	return 0;
}
