#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int width, N;
int set_cnt;
int arr[1'00'000];
int point[1'000'000];
int parent[1'00'000];

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

	parent[t2] = t1;
	point[t1] += point[t2];
	point[t2]  = 0;
	set_cnt--;
}

void init() {
	for (int i = 0; i < width; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < width; i++) {
		arr[i] = -1;
	}

	for (int i = 0; i < width; i++) {
		point[i] = 1;
	}
}

int main() {
	std::cin >> width >> N;
	
	init();

	for (int i = 0; i < N; i++) {
		int idx;
		std::cin >> idx;

		arr[idx] = idx;
		set_cnt++;

		if (idx != 0 && arr[idx - 1] != -1) {
			setUnion(idx - 1, idx);
		}
		
		if (idx != width-1 && arr[idx + 1] != -1) {
			setUnion(idx + 1, idx);
		}

		std::cout << set_cnt << " "<< * max_element(point, point + N) << '\n';
	}


	return 0;
}
