#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int width, N;
    if (!(cin >> width >> N)) return 0;

    vector<int> pos(N);
    for (int i = 0; i < N; ++i) cin >> pos[i];

    // DSU arrays
    vector<int> parent(width, -1);   // -1이면 아직 돌이 없음
    vector<int> sz(width, 0);
    vector<char> active(width, 0);

    auto find_set = [&](int v) {
        while (parent[v] != v) {
            parent[v] = parent[parent[v]]; // path halving
            v = parent[v];
        }
        return v;
    };

    auto unite = [&](int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return sz[a]; // 이미 같은 집합
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        return sz[a]; // 새 루트 a의 사이즈
    };

    long long groups = 0; // 현재 연결 컴포넌트 수
    int max_size = 0;     // 가장 큰 컴포넌트 크기

    for (int i = 0; i < N; ++i) {
        int p = pos[i];

        if (!active[p]) {
            // 새로 돌 올림: make-set
            active[p] = 1;
            parent[p] = p;
            sz[p] = 1;
            groups += 1;
            max_size = max(max_size, 1);

            // 왼쪽 이웃
            if (p - 1 >= 0 && active[p - 1]) {
                int rp = find_set(p), rl = find_set(p - 1);
                if (rp != rl) {
                    groups -= 1;
                    int newSize = unite(rp, rl);
                    max_size = max(max_size, newSize);
                }
            }
            // 오른쪽 이웃
            if (p + 1 < width && active[p + 1]) {
                int rp = find_set(p), rr = find_set(p + 1);
                if (rp != rr) {
                    groups -= 1;
                    int newSize = unite(rp, rr);
                    max_size = max(max_size, newSize);
                }
            }
        }
        // 이미 돌이 있던 칸이 들어오면 상태 변화 없이 출력
        cout << groups << ' ' << max_size << "\n";
    }
    return 0;
}
