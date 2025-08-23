#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	std::ios::sync_with_stdio(false);

	cin >> T;
	for (test_case = 1; test_case <= T; test_case++)
	{
		int n;
		cin >> n;
		int height[101];
		for (int i = 0; i < 101; i++) {
			height[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> height[i];
		}

		sort(height, height + n);

		// 최대 키인 나무가 여러 개 있을 수 있다는 점을 고려
		int* max_ptr = max_element(height, height + n);
		int max_idx = max_ptr - height;
		int max = *max_ptr;

		// 가장 큰 키가 되기 위해 필요한 2와 1의 갯수 count
		int two = 0; int one = 0;
		for (int i = 0; i <= max_idx - 1; i++) {
			int add_two = (max - height[i]) / 2;
			int add_one = (max - height[i]) % 2;

			two += add_two;
			one += add_one;
		}

		// d 구하기
		int d = abs((one - two)) / 3;
		int dd = abs((one - two)) % 3;

		// one, two를 "최소 일수"가 나오도록 보정해 준다
		// one, two의 차이가 1일때 "최소 일수"가 보장됨
		int cal_one = one; int cal_two = two;
		while (true) {
			int stopper = abs(cal_one - cal_two);
			if (stopper == 1 || cal_one-cal_two>=0)
				break;
			cal_two -= 1;
			cal_one += 2;
		}


		// 답구하기 : cal_one - cal_two>0 일때만 +1 해주고 
		// 나머지는 date = 2*(cal_two)
		int date;
		if (cal_one - cal_two > 0)
		{
			date = cal_two * 2 + (cal_one - cal_two) * 2 - 1;
		}
		else
		{
			date = cal_two * 2;
		}

		cout << "#" << test_case << " " << date << endl;
	}

	return 0; // 정상종료시 반드시 0을 리턴해야 합니다.
}