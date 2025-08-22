// [방법 1]
// -----------------------------------------------------------
#include <iostream>
using namespace std;

int main() {
	string str;
	std::cin >> str;

	int arr[150] = {};
	for (char x : str) {
		if (x != '\0') {
			arr[x]++;
		}
	}

	int max_val = 0;
	int min_val = 21e8;
	int max_idx = -1;
	int min_idx = -1;

	for (int i = 0; i < 150; i++) {
		if (max_val < arr[i]) {
			max_val = arr[i];
			max_idx = i;
		}

		if (min_val > arr[i] && 'A' <= i && i <= 'K') {
			min_val = arr[i];
			min_idx = i;
		}
	}

	std::cout << char(max_idx) << '\n' << char(min_idx);
	return 0;
}
// -----------------------------------------------------------


// [방법 2]
// -----------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int dat[100] = { 0 };
	string str;

	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		dat[str[i]]++;
	}

	char min = 'A';
	char max = 'A';
	for (int i = 'A'; i <= 'K'; i++) {
		if (dat[min] > dat[i]) min = i;
		if (dat[max] < dat[i]) max = i;
	}

	cout << max << "\n" << min;

	return 0;
}
// -----------------------------------------------------------
