#include <iostream>
#include <string>
using namespace std;

string curse;
string devil, engel;
string tmp;
int d_visit[101], e_visit[101];
int cnt; 

void dfs1(int n, int idx);
void dfs2(int n, int idx);

void dfs1(int n, int idx) {
	
	if (n == curse.size()) {
		if(tmp == curse)
			cnt++;
		return;
	}
	for (int i = idx; i < devil.size(); i++)
	{
		if (d_visit[i])continue;
		if (devil[i] != curse[n])continue;
		d_visit[i] = 1;
		tmp += devil[i];
		dfs2(n + 1, i + 1);
		tmp = tmp.substr(0, tmp.size()-1);
		d_visit[i] = 0;
	}
}
void dfs2(int n, int idx) {
	if (n == curse.size()) {
		if (tmp == curse)
			cnt++;
		return;
	}
	for (int i = idx; i < engel.size(); i++)
	{
		if (e_visit[i])continue;
		if (engel[i] != curse[n])continue;
		e_visit[i] = 1;
		tmp += engel[i];
		dfs1(n + 1, i + 1);
		tmp = tmp.substr(0, tmp.size()-1);
		e_visit[i] = 0;
	}
}
int main() {
	cin >> curse >> devil >> engel;
	dfs1(0, 0);
	dfs2(0, 0);

	cout << cnt;
}
