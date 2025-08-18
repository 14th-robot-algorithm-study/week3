#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T, N;
int ans;
int people[20];
int trainUser1;
int trainUser2;

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		ans = 0;
		memset(people, 0, sizeof(people));

		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> people[i];
		}

		for (int i = 0; i < N; i++) {	//첫번째 직통 노선1
			for (int j = 0; j < N; j++) {
				/*======     인접한 경우 제거     =====*/
				if (i == j) continue;
				if (abs(i - j) >= N - 1 || abs(i - j) <= 1) continue;
				/*======     인접한 경우 제거     ======*/
				trainUser1 = (people[i] + people[j]) * (people[i] + people[j]);

				for (int a = 0; a < N; a++) {
					/*======     인접한 경우 제거     =====*/
					if (a == i || a == j) continue;
					if (abs(a - i) >= N - 1 || abs(a - i) <= 1) continue;
					if (abs(a - j) >= N - 1 || abs(a - j) <= 1) continue;
					/*======     인접한 경우 제거     =====*/
					for (int b = 0; b < N; b++) {
						/*======     인접한 경우 제거     =====*/
						if (b == i || b == j || b == a) continue;
						if (abs(b - i) >= N - 1 || abs(b - i) <= 1) continue;
						if (abs(b - j) >= N - 1 || abs(b - j) <= 1) continue;
						if (abs(b - a) >= N - 1 || abs(b - a) <= 1) continue;
						/*======     인접한 경우 제거     =====*/
						
						/*======     교차하는 경우 제거     =====*/
						if ((a >= i && a <= j) || (b >= i && b <= j)) continue;
						if ((a >= j && a <= i) || (b >= j && b <= i)) continue;


						trainUser2 = (people[a] + people[b]) * (people[a] + people[b]);

						ans = max(ans, trainUser1 + trainUser2);
					}
				}
			}
		}

		cout << "#" << tc << " " << ans << "\n";
	}
}
