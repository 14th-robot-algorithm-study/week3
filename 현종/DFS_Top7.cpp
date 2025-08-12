#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;      
vector<vector<int>> rev_adj;  
vector<bool> visited;        

int dfs_for_better(int st) {
    visited[st] = true;
    int count = 0;

    for (int neighbor : rev_adj[st]) { 
        if (!visited[neighbor]) {
            count += 1 + dfs_for_better(neighbor);
        }
    }
    return count;
}


int dfs_for_worse(int st) {
    visited[st] = true;
    int count = 0;

    for (int neighbor : adj[st]) {
        if (!visited[neighbor]) {
            count += 1 + dfs_for_worse(neighbor);
        }
    }
    return count;
}


int main() {

    int N, M, X;
    cin >> N >> M >> X;

    adj.resize(N + 1);
    rev_adj.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        rev_adj[B].push_back(A);
    }

    fill(visited.begin(), visited.end(), false);
    int better_count = dfs_for_better(X);

    fill(visited.begin(), visited.end(), false);
    int worse_count = dfs_for_worse(X);

    int U = 1 + better_count;
    int V = N - worse_count;

    cout << U << endl << V << endl;

    return 0;
}