#include <iostream>
#include <string>
using namespace std;

int main() {
	std::string str;
	std::cin >> str;

	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::string text;
		std::cin >> text;

		if (text.find(str) != std::string::npos) {
			std::cout << "O" << "\n";
		}
		else {
			std::cout << "X" << "\n";
		}
	}


	return 0;
}
