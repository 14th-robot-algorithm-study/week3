#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N;
int T;
int people[26];
int parent[26];
int alive;
string command[100];
vector <int> country[26];

int find(int t) {
	if (parent[t] == t) return t;
	return parent[t] = find(parent[t]);
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	parent[t2] = t1;
	people[t1] += people[t2];
	return;
}

int main() {
	cin >> N;
	alive = N;

	for (int i = 0; i < N; i++) parent[i] = i;

	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}
	cin >> T;
	for (int i = 0; i < T; i++) {
		char A, B;
		cin >> command[i] >> A >> B;
		int a = A - 'A';
		int b = B - 'A';

		if (command[i] == "alliance") {
			setUnion(a, b);
		}

		else if (command[i] == "war") {
			int rootA = find(a);
			int rootB = find(b);
			
			if (people[rootA] > people[rootB]) {
				for (int i = 0; i < N; i++) {
					if (find(i) == rootB) alive--;
				}
			}
			else if (people[rootB] > people[rootA]) {
				for (int i = 0; i < N; i++) {
					if (find(i) == rootA) alive--;
				}
			}
			else {
				for (int i = 0; i < N; i++) {
					if (find(i) == rootA) alive--;
					if (find(i) == rootB) alive--;
				}
			}
		}
	}

	cout << alive;
}
