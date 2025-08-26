// DP 생각 안나서 한 풀이
//#include <iostream>
//using namespace std;
//
//int min_val = 21e8;
//
//void dfs(int n, int cnt) {
//	if (cnt > min_val)return;
//	if (n == 1)
//		if (cnt < min_val)
//		{
//			min_val = cnt;
//			return;
//		}
//	if (!(n % 3))
//		dfs(n / 3, cnt + 1);
//	if (!(n % 2))
//		dfs(n / 2, cnt + 1);
//	dfs(n - 1, cnt + 1);
//}
//int main() {
//	int n;
//	cin >> n;
//
//	dfs(n, 0);
//
//	cout << min_val;
//}



#include <iostream>
#include <algorithm>
using namespace std;

int DP[1000000];

int main() {
	int N;
	cin >> N;

	for (int i = 2; i <= N; i++) {
		// 1. 1을 뺀다.
		DP[i] = DP[i - 1] + 1;

		// 2. 2로 나누어지면
		if (i % 2 == 0) {
			DP[i] = min(DP[i], DP[i / 2] + 1);
		}

		// 3. 3으로 나누어지면
		if (i % 3 == 0) {
			DP[i] = min(DP[i], DP[i / 3] + 1);
		}
	}

	cout << DP[N];

	return 0;
}
출처: https://beginnerdeveloper-lit.tistory.com/81 [초보 개발자의 이야기, 릿허브:티스토리]
