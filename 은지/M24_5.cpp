#include <iostream>
#include <string>
using namespace std;

int main() {
	string input[5];
	int cnt = 0;

	for (int i = 0; i < 5; i++) {
		std::cin >> input[i];
	}

	for (int i = 0; i < 5; i++) {
		int str_len = input[i].find("MCD");
		for (int j = str_len; j < input[i].size(); j+=3) {
			if (input[i].find("MCD", j) != string::npos) {
				cnt++;
			}
		}
	}

	std::cout << cnt;

	return 0;
}
