#include <iostream>
#include <string>
using namespace std;

string str;
string hell;
string heaven;
int cnt = 0;

void func(int lev, int mode, int place) {
	if (lev == str.size()) {
		cnt++;
		return;
	}


	for (int i = place; i < hell.size(); i++) {
		if (mode == 0 && str[lev] == hell[i]) {
			func(lev + 1, 1, i + 1);
		}

		else if (mode == 1 && str[lev] == heaven[i]) {
			func(lev + 1, 0, i + 1);
		}
	}
}

int main() {
	cin >> str >> hell >> heaven;

	func(0, 0, 0);
	func(0, 1, 0);

	cout << cnt;
}
