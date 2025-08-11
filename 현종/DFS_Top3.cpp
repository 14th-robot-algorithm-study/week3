#include<iostream>
#include<vector>
using namespace std;

int tr[1001][2];
vector<int> preorder;
vector<int> inorder;
vector<int> postorder;
void dfs(int now) {
	//-1은 없는 것
	if (now == -1)return;
	preorder.push_back(now);
	//왼쪽 탐색
	dfs(tr[now][0]);
	inorder.push_back(now);
	//오른쪽 탐색
	dfs(tr[now][1]);
	postorder.push_back(now);
}

int main() {

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) { 
		int root, left, right;
		cin >> root >> left >> right;
		tr[root][0] = left;
		tr[root][1] = right;
	}

	dfs(1);

	for (int i = 0; i < inorder.size(); i++) {
		cout << inorder[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < preorder.size(); i++) {
		cout << preorder[i] << " ";
	}
	cout << '\n';
	for (int i = 0; i < postorder.size(); i++) {
		cout << postorder[i] << " ";
	}
	return 0;
}
