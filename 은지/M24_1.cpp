#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	std::string str;
	std::cin >> str;

	std::cout << str << "\n";
	std::reverse(str.begin(), str.end());
	std::cout << str;

	return 0;
}
