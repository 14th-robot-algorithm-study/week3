#include <iostream>
using namespace std;

int DP[1000];
int main() {
	int n;

	cin >> n;
	DP[0] = 1;
	DP[1] = 1;
	DP[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
		DP[i] %= 10007;
	}

	cout << DP[n];
}
