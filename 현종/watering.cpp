#include <iostream>
#include <algorithm>
using namespace std;
int T, N;
int tree[101];
int diff[101];
int cur;
int cnt;
int main() {
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cnt = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> tree[i];
		}

		sort(tree, tree+N);

		for (int i = 0; i < N-1; i++)
		{
			diff[i] = tree[N - 1] - tree[i];
			if (!diff[i])cnt++;
		}

		sort(diff, diff + N - 1);
		int day = 0;

		while (1) {
			cur = -1;
			if (cnt == N - 1)break;
			day++;
			for (int i = 0; i < N; i++)
			{
				if (diff[i] == 1 && day % 2) {
					cur = i;
					break;
				}
				else if (diff[i] == 2 && !(day % 2)) {
					cur = i;
					break;
				}
				else if (diff[i] >= 3) {
					cur = i;
					break;
				}
				else
					continue;
			}
			if (cur == -1)continue;
			if (day % 2) {
				diff[cur] -= 1;
			}
			else {
				diff[cur] -= 2;
			}

			if (!diff[cur])cnt++;

			
		}
		cout << "#" << tc << " " << day << "\n";
	}
}