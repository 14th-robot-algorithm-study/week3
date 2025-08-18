// ===================== [방법 1] =====================
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
// ====================================================


// ===================== [방법 2] =====================
#include <iostream>
using namespace std;

int N; 
int parent[26];
int pop[26]; 
int isAlive[26]; 

int Find(int now) {
	if (now == parent[now])
		return now;
	return parent[now] = Find(parent[now]);
}

void Union(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	if (pa == pb)
		return;
	parent[pb] = pa;
	pop[pa] += pop[pb];
	pop[pb] = 0;
}

void war(int a, int b) {
	int pa = Find(a);
	int pb = Find(b);
	
	if (pa == pb)
		return;
	
	if (pop[pa] > pop[pb]) {
		pop[pb] = 0; 
	}
	else if (pop[pb] > pop[pa]) {
		pop[pa] = 0; 
	}
	else {
		pop[pa] = 0;
		pop[pb] = 0; 
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pop[i];
		parent[i] = i; 
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		string cmd;
		char A, B;
		cin >> cmd >> A >> B;
		int a = A - 'A';
		int b = B - 'A';

		if (cmd == "alliance") {
			Union(a, b);
		}
		else {
			war(a, b);
		}
	}

	int cnt = 0; 
	for (int i = 0; i < N; i++) {
		if (pop[Find(i)] != 0)
			cnt++;
	}
	cout << cnt;
}
// ====================================================
