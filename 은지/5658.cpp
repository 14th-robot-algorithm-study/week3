#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool compare(std::string v1, std::string v2) {
	return v1 > v2;
}

int main() {
	int T;
	std::cin >> T;

	for (int i = 1; i < T + 1; i++) {
		int N, K;
		std::cin >> N >> K;
		int slice = N / 4;

		std::string str;
		std::cin >> str;

		std::vector <std::string> v;

		for (int i = 0; i < slice; i++) {
			for (int j = 0; j < N; j += slice) {
				v.push_back(str.substr(j, slice));
			}

			str = str.back() + str.substr(0, str.length() - 1);
		}

		std::sort(v.begin(), v.end(), compare);
		v.erase(unique(v.begin(), v.end()), v.end());

		std::cout << "#" << i << " " << stoi(v[K - 1], nullptr, 16) << "\n";
	}


	return 0;
}
