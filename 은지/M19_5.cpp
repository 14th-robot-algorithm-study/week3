#include <iostream>
using namespace std;

struct MC {
	char burger1[8];
	char burger2[8];
};

int len(char arr[8]) {
	for (int i = 0; i < 8; i++) {
		if (arr[i] == '\0') {
			return i;
		}
	}
}

int main() {
	MC bob, tom;

	std::cin >> bob.burger1 >> bob.burger2;
	std::cin >> tom.burger1 >> tom.burger2;

	std::cout << "bob.burger1=" << len(bob.burger1) << '\n';
	std::cout << "bob.burger2=" << len(bob.burger2) << '\n';
	std::cout << "tom.burger1=" << len(tom.burger1) << '\n';
	std::cout << "tom.burger2=" << len(tom.burger2);

	return 0;
}
