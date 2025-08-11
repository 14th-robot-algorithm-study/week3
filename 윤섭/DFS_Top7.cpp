#include <iostream>
#include <vector>
using namespace std;

int N, M, X;
int U, V;
vector<vector<int>> v1;
vector<vector<int>> v2;
int visited1[100000];
int visited2[100000];

int winPlace;
int losePlace;
void front(int lev) {

	for (int i = 0; i < v1[lev].size(); i++) {
		if (visited1[v1[lev][i]] == 1) continue;
		visited1[v1[lev][i]] = 1;
		winPlace++;
		front(v1[lev][i]);
	}
}

void back(int lev) {
	for (int i = 0; i < v2[lev].size(); i++) {
		if (visited2[v2[lev][i]] == 1) continue;
		visited2[v2[lev][i]] = 1;
		losePlace++;
		back(v2[lev][i]);
	}
}


int main() {
	cin >> N >> M >> X;

	v1.resize(N + 1);
	v2.resize(N + 1);

	for (int i = 0; i < M; i++) {
		int win, lose;
		cin >> win >> lose;
		v1[win].push_back(lose);
		v2[lose].push_back(win);
	}
	visited1[X] = 1;
	visited2[X] = 1;
	front(X);
	back(X); 
	cout << 1 + losePlace << "\n" << N - winPlace;
}
