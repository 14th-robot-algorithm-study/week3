#include <iostream>
using namespace std;

int main() {
	int n, l, d;
	cin >> n >> l >> d;

	// 전체 재생 시간: 마지막 노래까지
	int endTime = n * l + (n - 1) * 5;

	for (int t = d; ; t += d) {
		bool isBusy = false;

		// 노래 + 쉬는 시간 체크
		for (int i = 0; i < n; i++) {
			int start = i * (l + 5);

			if (t >= start && t < start + l) {
				isBusy = true; // 노래 중
				break;
			}
		}

		if (!isBusy) {
			cout << t;
			return 0;
		}
	}
}
