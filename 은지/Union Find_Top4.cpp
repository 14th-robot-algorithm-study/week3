#include <iostream>
#include <string>
using namespace std;

int N, T, cnt;
int val1, val2;
int arr[26];
int parent[26];
int human[26];
bool flag[26];

int find(int tar) {
	if (tar == parent[tar]) {
		return tar;
	}

	return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);

	if (t1 == t2) {
		return;
	}

	if (t1 < t2) {
		parent[t2] = t1;
	}
	else {
		parent[t1] = t2;
	}


}

int main() {
	for (int i = 0; i < 26; i++) {
		parent[i] = i;
	}

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> arr[i];
	}

	std::cin >> T;

	for (int i = 0; i < T; i++) {
		string str;
		char a, b;
		std::cin >> str >> a >> b;

		a = a - 'A';
		b = b - 'A';

		if (str == "alliance") {
			setUnion(a, b);
		}
		else if (str == "war") {
			cnt = 0;
			val1 = 0;
			val2 = 0;

			for (int i = 0; i < N; i++) {
				if (find(i) == find(a)) {
					val1 += arr[i];
				}

				if (find(i) == find(b)) {
					val2 += arr[i];
				}
			}


			if (val1 > val2) {
				for (int i = 0; i < N; i++) {
					if (find(i) == find(b)) {
						flag[i] = true;
					}

					if (!flag[i]) {
						cnt++;
					}
				}
			}
			else if (val1 < val2) {
				for (int i = 0; i < N; i++) {
					if (find(i) == find(a)) {
						flag[i] = true;
					}

					if (!flag[i]) {
						cnt++;
					}
				}
			}
			else {
				for (int i = 0; i < N; i++) {
					if (find(i) != find(a) && find(i) != find(b)) {
						cnt++;
					}
				}
			}
		}
	}

	std::cout << cnt;

	return 0;
}
