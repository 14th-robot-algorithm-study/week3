#include <iostream>
#include <string>
using namespace std;


int main() {
	string str;
	cin >> str;

	int data[4];

	for (int i = 0; i < 4; i++) {
		cin >> data[i];
	}

	char* ptrs[4] = { &str[data[0]], &str[data[1]], &str[data[2]], &str[data[3]] };

	for (int i = 0; i < 4; i++) {
		cout << *ptrs[i];
	}
}
