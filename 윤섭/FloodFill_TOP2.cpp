
검색




completed tasks image
Well done. You’ve completed all of the tasks!
We hope Mattermost is more familiar now.
Got it
Now that you’re all set up, download our apps.

채널 탐색

채널

개인 메시지

2
5
5
4

At 오후 2:04 8월 12일 화요일, 서정우[광주_3반] wrote, ```cpp #define _CRT_SECURE_NO_WARNINGS #include <iostream> #include <queue> #include <algorithm> using namespace std; int height, width; int visited[101][101]; int dy[4] = { -1, 1, 0, 0 }; int dx[4] = { 0, 0, -1, 1 }; int cnt; struct Point { int y, x; }; void bfs(Point st, Point st2) { queue<Point> q; visited[st.y][st.x] = 1; visited[st2.y][st2.x] = 1; q.push(st); q.push(st2); while (!q.empty()) { Point cur = q.front(); q.pop(); for (int i = 0; i < 4; i++) { Point np = { cur.y + dy[i], cur.x + dx[i] }; if (np.y < 0 || np.x < 0 || np.y >= height || np.x >= width) continue; if (visited[np.y][np.x]) continue; visited[np.y][np.x] = visited[cur.y][cur.x] + 1; q.push(np); cnt = max(cnt, visited[np.y][np.x]); } } } int main() { cin >> height >> width; Point a; Point b; cin >> a.y >> a.x; cin >> b.y >> b.x; bfs(a, b); cout << cnt; return 0; } ```

류광철[광주_3반]
오전 10:51
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int N;

int map[15][15];
int visited[15];


void bfs(int st)
{
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
                continue;
            if (!map[cur][i])
                continue;
            
            visited[i] = 1;
            q.push(i);
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }
    
    bfs(0);
    cout << "\n";
}
더보기

한용만[광주_3반]
오전 10:52
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
int map[10][10];
int visited[10];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1};

void bfs(int st) {
    queue<int> q;
    visited[st] = 1;
    q.push(st);
    cout << st << " ";
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (visited[i] || !map[cur][i])
                continue;
            cout << i << " ";
            visited[i] = 1;
            q.push(i);
        }
    }
}

int main() {
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    bfs(0);
    return 0;
}
더보기

김준영[광주_3반]
오전 10:52
#include <iostream>
#include <queue>

int map[10][10];
int visited[10];
int main() {
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n ; j++) std::cin >> map[i][j];
    }
    std::queue<int> q;
    q.push(0); visited[0] = 1;

    while(!q.empty()){
        std::cout << q.front() << " ";
        for(int i = 0; i < n; i++){
            if(!map[q.front()][i]) continue;
            if(visited[i]) continue;

            q.push(i);
            visited[i] = 1;
        } 
        q.pop();
    }
    return 0;
}

서민규[광주_3반]
오전 10:52
#include <iostream>
#include <queue>

using namespace std;

int N;
int visited[11];
int map[11][11];

void bfs(int st)
{
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();
        cout << cur << ' ';
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (visited[i]) continue;
            if (map[cur][i] == 0) continue;
            visited[i] = 1;
            q.push(i);
        }
    }
}

int main()
{
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

    bfs(0);

    return 0;
}
더보기

최윤섭[광주_3반]
오전 10:53
#include <iostream>
#include <queue>
using namespace std;

int N;
int map[10][10];
int visited[10];

void func(int st) {
    queue<int> q;
    visited[st] = 1;
    q.push(st);
    cout << st << " ";

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
            if (visited[i] == 1) continue;
            if (map[cur][i] == 0) continue;
            cout << i << " ";
            visited[i] = 1;
            q.push(i);
        }
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    func(0);
}
더보기

곽명철[광주_3반]
오전 10:53
#include<iostream>
#include<queue>
using namespace std;

int N;
int map[10][10];
int visited[10];

void BFS(int node);

int main(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> map[i][j];
    }

    BFS(0);

    return 0;
}

void BFS(int node)
{
    queue<int>q;
    visited[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int cur = q.front();
        cout << cur << " ";
        q.pop();

        for (int i = 0; i < N; i++)
        {
            if (visited[i])
                continue;
            if (map[cur][i] == 0)
                continue;
            visited[i] = 1;
            q.push(i);
        }
    }
}
더보기

고형권[광주_3반]
오전 10:54
#include <iostream>
#include <queue>

using namespace std;

int N;
int map[10][10];
int visited[10];

void bfs(int st)
{
    queue<int> q;
    visited[st] = 1;
    q.push(st);
    cout << st << " ";

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < N; i++)
        {
            if (visited[i])
                continue;
            if (map[cur][i] == 0)
                continue;
            visited[i] = 1;
            cout << i << " ";
            q.push(i);
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
        }
    }

    bfs(0);
}
더보기

오충민[광주_3반]
오전 10:54
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int n;

int map[10][10];
int visited[10];

void bfs(int st)
{
    queue<int> q;
    q.push(st);
    visited[st] = 1;
    while (!q.empty())
    {
        int to = q.front();
        q.pop();
        cout << to << " ";

        for(int i=0;i<n;i++)
        { 
            if (visited[i])
            {
                continue;
            }
            if (map[to][i] == 0)
            {
                continue;
            }
            visited[i] = 1;
            q.push(i);
        }

    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }
    bfs(0);
    return 0;
}
더보기

서정우[광주_3반]
오전 10:55
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N;
int MAP[11][11];
int visited[11];
int cur;

void bfs(int st) {
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (visited[i] == 1) continue;
            if (MAP[cur][i] == 0) continue;
            visited[i] = 1;
            q.push(i);
        }
        cout << cur << ' ';
    }
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> MAP[i][j];
        }
    }

    bfs(0);

    return 0;
}
더보기

하은지[광주_3반]
오전 10:55
#include <iostream>
#include <queue>
using namespace std;

int N;
int arr[11][11];
int visited[11];

void bfs(int st) {
    queue <int> q;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        std::cout << cur << " ";
        q.pop();

        for (int i = 0; i < N; i++) {
            if (visited[i] == 1) {
                continue;
            }

            if (arr[cur][i] == 0) {
                continue;
            }

            visited[i] = 1;
            q.push(i);
        }
    }
}

int main() {
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> arr[i][j];
        }
    }
    visited[0] = 1;
    bfs(0);
    return 0;
}
더보기

이자룡 강사[광주_3반]
오전 10:55
Flood Fill 탑 1 - Flood Fill

이용이[광주_3반]
오전 11:01
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n = 5;
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int visited[5][5];
int d[5][5];
struct Pos {
    int i, j;
};
void bfs(Pos st) {
    queue<Pos> q;
    q.push(st);
    visited[st.i][st.j] = true;
    d[st.i][st.j] = 1;
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        //cout << cur.i << " " << cur.j << '\n';
        for (size_t k = 0; k < 4; k++)
        {
            Pos next = { cur.i + di[k],cur.j + dj[k] };
            if (next.i < 0 || next.i >= 5 || next.j < 0 || next.j >= 5) {
                continue;
            }
            if (visited[next.i][next.j]) {
                continue;
            }
            visited[next.i][next.j] = true;
            d[next.i][next.j] = d[cur.i][cur.j] + 1;
            q.push(next);
        }
    }
}

int main()
{
    int si, sj;
    cin >> si >> sj;
    bfs({ si,sj });
    for (int i = 0; i < 5; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}
더보기

김준영[광주_3반]
오전 11:01
#include <iostream>
#include <queue>

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
int map[5][5];

int main() {
    int x, y;
    std::cin >> y >> x;
    map[y][x] = 1;
    std::queue<std::pair<int,int>> q;
    q.push({y,x});

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int dir = 0; dir < 4; dir++){
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if(ny < 0 || nx < 0 || ny >= 5 || nx >= 5) continue;
            if(map[ny][nx]) continue;

            map[ny][nx] = map[cy][cx] + 1;
            q.push({ny,nx});
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++) std::cout << map[i][j] << " ";
        std::cout << "\n";
    }
}
더보기

류광철[광주_3반]
오전 11:04
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int map[5][5];
int visited[5][5];

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

struct Point
{
    int y, x;
};

bool inRange(int y, int x) {
    if (y < 0 || x < 0 || y >= 5 || x >= 5) {
        return false;
    }
    return true;
}

void bfs(Point st)
{
    queue<Point> q;
    q.push(st);
    visited[st.y][st.x] = 1;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (!inRange(ny, nx))
                continue;
            if (visited[ny][nx])
                continue;
            visited[ny][nx] = visited[cur.y][cur.x] + 1;
            q.push({ ny, nx });
        }
    }
}

int main()
{
    int x, y;

    cin >> x >> y;

    bfs({x, y});

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
더보기

최윤섭[광주_3반]
오전 11:06
#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int y, x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[5][5];

void func(Point st) {
    queue <Point> q;
    visited[st.y][st.x] = 1;
    q.push(st);

    while (!q.empty()) {
        Point cp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point np = { cp.y + dy[i], cp.x + dx[i] };
            if (np.y < 0 || np.x < 0 || np.y >= 5 || np.x >= 5)
                continue;
            if (visited[np.y][np.x] > 0) continue;

            visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
            q.push(np);
        }
    }
}

int main() {
    int stY, stX;
    cin >> stY >> stX;

    func({ stY, stX });

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }
}
더보기

안지수[광주_3반]
오전 11:07
#include <iostream>
#include <queue>
using namespace std;

int visited[5][5];

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

struct Point {
    int y, x;
};

void bfs(Point st) {
    // start node
    queue<Point> q;
    visited[st.y][st.x] = 1;
    q.push(st);

    while (!q.empty()) {
        Point cp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            Point np = { cp.y + dy[i], cp.x + dx[i] };

            if (np.y >= 5 || np.y < 0 || np.x >= 5 || np.x < 0) continue;
            if (visited[np.y][np.x]) continue;

            visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
            q.push(np);
        }
    }

}


int main() {
    Point input;
    cin >> input.y >> input.x;

    bfs(input);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
더보기

곽명철[광주_3반]
오전 11:13
#include<iostream>
#include<queue>
using namespace std;

struct Pos {
    int y, x;
};

int visited[5][5];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

void BFS(Pos st);

int main(void)
{
    int startY, startX;
    cin >> startY >> startX;

    BFS({ startY,startX });

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << visited[i][j] << " ";
        cout << '\n';
    }

    return 0;
}

void BFS(Pos st)
{
    queue<Pos>q;
    visited[st.y][st.x] = 1;
    q.push(st);

    while (!q.empty())
    {
        Pos temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            Pos np = { temp.y + dy[i],temp.x + dx[i] };

            if (np.y >= 5 || np.y < 0 || np.x >= 5 || np.x < 0)
                continue;
            if (visited[np.y][np.x])
                continue;

            visited[np.y][np.x] = visited[temp.y][temp.x] + 1;
            q.push(np);
        }
    }
}
더보기

이용이[광주_3반]
오전 11:23
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>


using namespace std;
vector<int> adj[100'000 + 1];
bool visited[100'000 + 1] = { false };
int main()
{
    //1촌으로 연결타고 갈수 있는 모두에게 공유
    int n, m;
    cin >> n >> m;
    
    for (size_t i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int target;
    cin >> target;
    int cnt = 0;
    queue<int> q;
    q.push(target);
    visited[target] = true;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;
        for (int next : adj[cur]) {
            if (visited[next]) {
                continue;
            }
            visited[next] = true;
            q.push(next);
        }

    }
    cout << cnt-1;
    return 0;
}
더보기

이자룡 강사[광주_3반]
오전 11:23
BFS 탑 3번

코스타그램


오충민[광주_3반]
오전 11:29
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[100001];
vector<int> v[100001];
int st;
int num = 0;
void bfs(int st)
{
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int to = v[cur][i];

            if (visited[to])
                continue;
            visited[to] = 1;
            num++;
            q.push(to);
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    cin >> st;
    bfs(st);
    cout << num << endl;


}
더보기

김준영[광주_3반]
오전 11:31
#include <iostream>
#include <queue>
#include <vector>

std::vector<std::vector<int>> vec;
int visited[100001];

int main() {
    int n, m;
    std::cin >> n >> m;
    vec = std::vector<std::vector<int>>(n+1, std::vector<int>());
    for(int i = 0; i < m; i++){
        int a, b;
        std::cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    int c;
    std::cin >> c;

    std::queue<int> q;
    q.push(c); visited[c] = 1;    
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        for(int i = 0; i < vec[cur].size(); i++){
            if(visited[vec[cur][i]]) continue;
            
            visited[vec[cur][i]] = 1;
            q.push(vec[cur][i]);
        }
    }
    int cnt = 0;
    for(int i = 0; i <= n; i++) if(visited[i]) cnt++;
    std::cout << cnt - 1;
}
더보기

한승희[광주_3반]
오전 11:32
#include <iostream>
#include <vector>
#include <queue>

int n, m;
std::vector<int> people[100001];
int visited[100001];

int cnt = 0;

void bfs(int st) {
    std::queue<int> q;
    q.push(st);
    visited[st] = 1;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < people[cur].size(); i++) {
            if (visited[people[cur][i]]) {
                continue;
            }

            cnt++;
            visited[people[cur][i]] = 1;
            q.push(people[cur][i]);
        }
    }
}

int main() {
    std::cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;

        people[a].push_back(b);
        people[b].push_back(a);
    }

    int num;
    std::cin >> num;

    bfs(num);

    std::cout << cnt;
    return 0;
}
더보기

최윤섭[광주_3반]
오전 11:33
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, stUser, cnt;
vector<int> v[100001];
int visited[100001];

void bfs(int st) {
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (visited[next]) continue;
            visited[next] = 1;
            cnt++; 
            q.push(next);
        }
    }
}

int main() {

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }

    cin >> stUser;
    bfs(stUser);

    cout << cnt;
}

더보기

곽명철[광주_3반]
오전 11:34
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int N,M,COCO,countNum;
int visited[100001];
vector<int>v[100001];

void BFS(int node);

int main(void)
{
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    cin >> COCO;

    BFS(COCO);

    cout << countNum;

    return 0;
}

void BFS(int node)
{
    queue<int>q;
    visited[node] = 1;
    q.push(node);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            int next = v[cur][i];
            if (visited[next])
                continue;
            visited[next] = 1;
            q.push(next);
            countNum++;
        }
    }

}
더보기

이자룡 강사[광주_3반]
오전 11:34
5


손동완[광주_3반]
오전 11:34
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int cnt;

vector<vector<int>> costagram;
vector<int> visited;

void bfs(int st) {

    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int i = 0; i < costagram[cur].size(); i++)
        {
            int next = costagram[cur][i];
            // 방문 체크
            if (visited[next] == 1) continue;

            // 방큐
            visited[next] = 1;
            q.push(next);
            cnt++;
        }
    }
}

int main() {

    int from, to;

    cin >> N >> M;

    // 0번 idx 사용 안 함
    costagram.resize(N+1,vector<int>());
    visited.resize(N + 1,0);
    

    for (int i = 0; i < M; i++)
    {
        cin >> from >> to;
        costagram[from].push_back(to);
        costagram[to].push_back(from);
    }

    bfs(1);

    cout << cnt;


    return 0;
}
더보기

권순재[광주_3반]
오전 11:35
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M;
vector<int> v[100001];
int visited[100001];
int coco;
int cnt;

void bfs(int st)
{
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++)
        {
            int to = v[cur][i];
            if (visited[to])
                continue;
            visited[to] = 1;
            q.push(to);
        }
        cnt++;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from); //양방향으로 저장함.
    }

    cin >> coco;

    bfs(coco);

    cout << cnt - 1 << '\n';
    return 0;
}
더보기

류광철[광주_3반]
오전 11:37
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int num;
int cnt;

vector<int> v[100001];
int visited[100001];

void bfs(int st) {
    queue<int> q;
    q.push(st);
    visited[st] = 1;

    while (!q.empty()) {
        cnt++;
        int cur = q.front();
        q.pop();
        for (int i = 0; i < v[cur].size(); i++)
        {
            if (visited[v[cur][i]])
                continue;
            visited[v[cur][i]] = 1;
            q.push(v[cur][i]);
        }
    }
}

int main()
{
    cin >> N >> M;

    for (int i = 0; i < M; i++)
    {
        int from, to;
        cin >> from >> to;

        v[from].push_back(to);
        v[to].push_back(from);
    }

    cin >> num;
    bfs(num);

    cout << cnt - 1 << "\n";
}
더보기

서정우[광주_3반]
오전 11:37
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K;
vector<int> v[100000];
int visited[100000];
int cnt = 0;

void bfs(int st) {
    queue<int> q;
    visited[st] = 1;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i];
            if (visited[next]) continue;
            visited[next] = 1;
            q.push(next);
            cnt += 1;
        }
    }
}

int main() {
    cin >> N;
    cin >> M;

    for (int i = 0; i < M; i++) {
        int from, to;
        cin >> from >> to;
        v[from].push_back(to);
        v[to].push_back(from);
    }
    cin >> K;

    bfs(K);

    cout << cnt;

    return 0;
}
더보기

정지용[광주_3반]
오전 11:40
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, cocoId, cnt;
vector<vector<int>> vect;
vector<bool> visited;

void init() {
    cin >> n >> m;
    vect.resize(n + 1);
    visited.resize(n + 1);
    cnt = 0;
}

void input() {
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        vect[from].push_back(to);
        vect[to].push_back(from);
    }

    cin >> cocoId;
}

void bfs(int st) {
    queue<int> q;
    visited[st] = true;
    q.push(st);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cnt++;

        for (int next : vect[cur]) {
            if (visited[next]) continue;
            visited[next] = true;
            q.push(next);
        }
    }
}

int main() {
    init();
    input();
    bfs(cocoId);

    cout << (cnt - 1);

    return 0;
}
더보기

이자룡 강사[광주_3반]
오전 11:40
Flood Fill 탑 - 2번 : Bloom

이용이[광주_3반]
오전 11:46
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct Pos {
    int i, j;
};
int h, w;
bool map[100][100];
int di[4] = { -1,1,0,0 };
int dj[4] = { 0,0,-1,1 };
int main()
{

    queue<Pos> q;
    queue<Pos> breed;
    cin >> h >> w;
    for (size_t i = 0; i < 2; i++)
    {
        int si, sj;
        cin >> si >> sj;
        Pos p = { si,sj };
        map[si][sj] = true;
        q.push(p);
    }
    int day = 1;
    int cnt = 2;
    while (cnt <h*w) {
        while (!breed.empty()) {
            auto cur = breed.front();
            breed.pop();
            if (map[cur.i][cur.j]) {
                continue;
            }
            map[cur.i][cur.j] = true;
            q.push(cur);
            cnt++;
        }
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            for (size_t k = 0; k < 4; k++)
            {
                Pos next = { cur.i + di[k],cur.j + dj[k] };
                if (next.i < 0 || next.i >= h || next.j < 0 || next.j >= w) {
                    continue;
                }
                if (map[next.i][next.j]) {
                    continue;
                }
                breed.push(next);
            }
        }
        /*
        for (size_t i = 0; i < h; i++)
        {
            for (size_t j = 0; j < w; j++)
            {
                cout << map[i][j] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        */
        if (cnt == h*w) {
            break;
        }
        day++;
    }
    cout << day;
    return 0;
}
더보기

오충민[광주_3반]
오전 11:55
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[101][101];

int num = 0;
int max_visited;
struct Point
{
    int y, x;
};
Point firstst;
Point secondst;

void bfs(Point firstst, Point secondst)
{
    queue<Point> q;
    visited[firstst.y][firstst.x] = 1;
    visited[secondst.y][secondst.x] = 1;
    q.push(firstst);
    q.push(secondst);

    while (!q.empty())
    {
        Point cp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point np = { cp.y + dy[i],cp.x + dx[i] };
            if (np.y < 0 || np.x < 0 || np.y >= n || np.x >= m)
            {
                continue;
            }
            if (visited[np.y][np.x])
            {
                continue;
            }
            visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
            q.push(np);
            max_visited = max(max_visited, visited[np.y][np.x]);
        }
        
    }
}

int main()
{
    cin >> n >> m;
    cin >> firstst.y>>firstst.x;
    cin >> secondst.y >> secondst.x;

    
    bfs(firstst,secondst);

    cout << max_visited << endl;

}
더보기

김준영[광주_3반]
오후 1:39
#include <iostream>
#include <queue>

int map[100][100];

int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};

int main() {
    int h, w;
    std::cin >> h >> w;

    int y1, x1; std::cin >> y1 >> x1;
    int y2, x2; std::cin >> y2 >> x2;

    std::queue<std::pair<int,int>> q;
    q.push({y1,x1}); map[y1][x1] = 1;
    q.push({y2,x2}); map[y2][x2] = 1;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

            if(ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if(map[ny][nx]) continue;

            map[ny][nx] = 1 + map[cy][cx];
            q.push({ny,nx});
        }
    }
    int max = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) max = std::max(max, map[i][j]);
    }
    std::cout << max;
}
더보기

이영현[광주_3반]
오후 1:39
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

typedef struct {
    int row, col;
}Point;

int n, m;
int map[101][101];
int dr[] = { -1,1,0,0 };
int dc[] = { 0,0,-1,1 };
queue<Point> q;
int maxVal;

void BFS() {
    while (!q.empty()) {
        Point now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.row + dr[i];
            int nc = now.col + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < m
                && !map[nr][nc]) {
                map[nr][nc] = maxVal = map[now.row][now.col] + 1;
                q.push({ nr,nc });
            }
        }
    }
}

int main() {

    cin >> n >> m;
    for (int i = 0; i < 2; i++) {
        int row, col;
        cin >> row >> col;
        map[row][col]++;
        q.push({ row,col });
    }

    BFS();

    cout << maxVal << '\n';

    return 0;
}
더보기

이자룡 강사[광주_3반]
오후 1:46
4


한용만[광주_3반]
오후 1:46
#define _CRT_SECURE_NO_WARNNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int y;
    int x;
};

const int dy[] = { -1, 1, 0, 0 };
const int dx[] = { 0, 0, -1, 1 };

int H, W;
int board[101][101];
int visited[101][101];
int max_day;

void BFS(Point st1, Point st2) {
    queue<Point> q;
    q.push(st1);
    q.push(st2);
    visited[st1.y][st1.x] = 1;
    visited[st2.y][st2.x] = 1;

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = cur.y + dy[d];
            int nx = cur.x + dx[d];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W ||
                visited[ny][nx]) {
                continue;
            }
            visited[ny][nx] = visited[cur.y][cur.x] + 1;
            max_day = max(max_day, visited[ny][nx]);
            q.push({ ny, nx });
        }

    }
}

int main() {
    cin >> H >> W;

    Point st1, st2;
    cin >> st1.y >> st1.x;
    cin >> st2.y >> st2.x;
    BFS(st1, st2);

    cout << max_day;
}
더보기

최윤섭[광주_3반]
오후 1:47
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int h, w;

struct Point {
    int y, x;
};

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int visited[100][100];
int day;

void bfs(Point st1, Point st2) {
    queue<Point> q;
    visited[st1.y][st1.x] = 1;
    visited[st2.y][st2.x] = 1;
    q.push(st1);
    q.push(st2);

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
            if (visited[ny][nx] > 0) continue;

            visited[ny][nx] = visited[cur.y][cur.x] + 1;
            q.push({ ny, nx });
            day = max(day, visited[ny][nx]);
        }
    }
}

int main() {
    cin >> h >> w;
    Point first, second;
    cin >> first.y >> first.x;
    cin >> second.y >> second.x;

    bfs({ first.y, first.x }, { second.y, second.x });

    cout << day;

}
감추기

이자룡 강사[광주_3반]
오후 1:49
6


서정민[광주_3반]
오후 1:49
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int h, w;
int visited[101][101];
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
int cnt = 0;
int max_val = 0;

struct Point {
    int y, x;
};

Point st1;
Point st2;

void bfs(Point st1, Point st2) {
    queue<Point> q;
    visited[st1.y][st1.x]=1;
    visited[st2.y][st2.x]=1;
    q.push(st1);
    q.push(st2);

    while (!q.empty()) {
        Point cp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            Point np = { cp.y + dy[i], cp.x + dx[i] };
            if (np.y < 0 || np.y >= h || np.x < 0 || np.x >= w) {
                continue;
            }
            if (visited[np.y][np.x]) {
                continue;
            }
            visited[np.y][np.x] = visited[cp.y][cp.x] + 1;
            q.push(np);
            max_val = max(max_val, visited[np.y][np.x]);
        }
    }
}

int main() {
    cin >> h >> w;
    cin >> st1.y >> st1.x;
    cin >> st2.y >> st2.x;

    bfs(st1, st2);
    cout << max_val;
    return 0;
}
더보기

고형권[광주_3반]
오후 1:50
#include <iostream>
#include <queue>

using namespace std;

int visited[100][100];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int height, width;
int day;

struct Point {
    int y;
    int x;
};

Point s1, s2;

void bfs(Point s1, Point s2)
{
    queue<Point> q;
    visited[s1.y][s1.x] = 1;
    visited[s2.y][s2.x] = 1;
    q.push(s1);
    q.push(s2);

    while (!q.empty())
    {
        int sz = q.size();
        for (int s = 0; s < sz; s++)
        {
            Point cur = q.front();
            q.pop();

            for (int d = 0; d < 4; d++)
            {
                int ny = cur.y + dy[d];
                int nx = cur.x + dx[d];

                if (ny < 0 || ny >= height || nx < 0 || nx >= width)
                    continue;
                if (visited[ny][nx])
                    continue;

                visited[ny][nx] = 1;
                q.push({ ny, nx });
            }
        }
        day++;
    }
}

int main()
{
    cin >> height >> width;
    cin >> s1.y >> s1.x;
    cin >> s2.y >> s2.x;

    bfs(s1, s2);

    cout << day;
}
더보기

이자룡 강사[광주_3반]
오후 1:53
8


손동완[광주_3반]
오후 1:56
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
using namespace std;

struct Point {
    int y, x;
};

int d[4][2] = {
    {-1,0},
    {0,1},
    {1,0},
    {0,-1},
};

int MAP[100][100];
int height, width;
int latest_date;

void bfs(Point one, Point two) {
    
    // 방문 푸시큐
    queue<Point> q;
    MAP[one.y][one.x] = 1;
    MAP[two.y][two.x] = 1;
    q.push(one);
    q.push(two);

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next;
            next.y = cur.y + d[i][0];
            next.x = cur.x + d[i][1];

            // 벽
            if(next.y < 0 || next.y >= height ||
                next.x < 0 || next.x >= width) {
                continue;
            }

            // 방문 여부
            if (MAP[next.y][next.x] != 0) { continue; }

            // 방문 푸시큐
            MAP[next.y][next.x] = MAP[cur.y][cur.x] + 1;
            q.push(next);

            latest_date = MAP[next.y][next.x];
        }
    }

}

int main() {

    cin >> height >> width;

    Point one, two;

    cin >> one.y >> one.x;
    cin >> two.y >> two.x;

    bfs(one, two);

    cout << latest_date;

    return 0;
}
더보기

류광철[광주_3반]
오후 1:58
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Point
{
    int y, x;
};

int height, width;

queue<Point> q1;
queue<Point> q2;

int dy[] = { -1, 1, 0, 0 };
int dx[] = { 0, 0, -1, 1 };

int max_val = -21e8;

bool inRange(int y, int x) {
    if (y < 0 || x < 0 || y >= height || x >= width) {
        return false;
    }
    return true;
}

int map[101][101];

void bfs() {

    while (!q1.empty() && !q2.empty()) {
        Point cur1 = q1.front();
        Point cur2 = q2.front();
        if (!q1.empty()) {
            q1.pop();
        }
        if (!q2.empty()) {
            q2.pop();
        }

        for (int i = 0; i < 4; i++)
        {
            int ny1 = cur1.y + dy[i];
            int nx1 = cur1.x + dx[i];
            if (!inRange(ny1, nx1))
                continue;
            if (map[ny1][nx1])
                continue;
            map[ny1][nx1] = map[cur1.y][cur1.x] + 1;
            max_val = max(max_val, map[ny1][nx1]);
            q1.push({ ny1, nx1 });
        }
        for (int i = 0; i < 4; i++)
        {
            int ny2 = cur2.y + dy[i];
            int nx2 = cur2.x + dx[i];
            if (!inRange(ny2, nx2))
                continue;
            if (map[ny2][nx2])
                continue;
            map[ny2][nx2] = map[cur2.y][cur2.x] + 1;
            max_val = max(max_val, map[ny2][nx2]);
            q2.push({ ny2, nx2 });
        }
    }
}

int main()
{
    cin >> height >> width;

    int y, x;

    cin >> y >> x;
    q1.push({y, x});
    map[y][x] = 1;

    cin >> y >> x;
    q2.push({ y, x });
    map[y][x] = 1;

    bfs();

    cout << max_val << "\n";

}
더보기

정인혁[광주_3반]
오후 1:58
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N = 5;
//int map[5][5];
int visited[10][10];
//vector<vector<int>> visited;
int h, w;
int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };
bool flag = false;
int bigbig = 0;
struct Point {
    int y, x;
};

bool full() {
    // 모두 가득차있는지 확인
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bigbig = max(bigbig, visited[i][j]);
            if (visited[i][j] < 1) {
                return false;
            }
        }
    }
    return true;
}

void bfs(Point st1, Point st2)
{
    queue<Point> q1;
    queue<Point> q2;

    visited[st1.y][st1.x] = 1;
    visited[st2.y][st2.x] = 1;
    q1.push(st1);
    q2.push(st2);


    while (!q1.empty() && !q2.empty()) {
        Point cur1 = q1.front();
        Point cur2 = q2.front();
        q1.pop();
        q2.pop();

        //cout << cur << " ";
        for (int i = 0; i < 4; i++) {
            int ny1 = cur1.y + dy[i];
            int nx1 = cur1.x + dx[i];
            
            
            if (nx1 < 0 || nx1 >= w || ny1 < 0 || ny1 >= h) continue;

            if (visited[ny1][nx1]) continue;
            visited[ny1][nx1] = visited[cur1.y][cur1.x] + 1;
            q1.push({ny1,nx1});
            if (full()) {
                flag = true;
                break;
            }
        }

        for (int i = 0; i < 4; i++) {
            int ny2 = cur2.y + dy[i];
            int nx2 = cur2.x + dx[i];

            if (nx2 < 0 || nx2 >= w || ny2 < 0 || ny2 >= h) continue;
            if (visited[ny2][nx2]) continue;
            visited[ny2][nx2] = visited[cur2.y][cur2.x] + 1;
            q2.push({ny2,nx2});

            if (full()) {
                flag = true;
                break;
            }
        }

        if (flag) {
            break;
        }

    }

}


int main()
{
    cin >> h >> w;
    //visited.assign(h,vector<int>(w,0));

    int y1, x1, y2, x2;
    cin >> y1 >> x1;
    cin >> y2 >> x2;

    bfs({ y1,x1 }, {y2,x2});

    cout << bigbig;
}
더보기

서정우[광주_3반]
오후 2:04
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int height, width;
int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int cnt;

struct Point {
    int y, x;
};

void bfs(Point st, Point st2) {
    queue<Point> q;
    visited[st.y][st.x] = 1;
    visited[st2.y][st2.x] = 1;
    q.push(st);
    q.push(st2);

    while (!q.empty()) {
        Point cur = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            Point np = { cur.y + dy[i], cur.x + dx[i] };

            if (np.y < 0 || np.x < 0 || np.y >= height || np.x >= width) continue;
            if (visited[np.y][np.x]) continue;

            visited[np.y][np.x] = visited[cur.y][cur.x] + 1;
            q.push(np);
            cnt = max(cnt, visited[np.y][np.x]);
        }
    }
}

int main() {
    cin >> height >> width;

    Point a;
    Point b;

    cin >> a.y >> a.x;
    cin >> b.y >> b.x;

    bfs(a, b);

    cout << cnt;

    return 0;
}
더보기
4. 온/오프라인코칭에 글쓰기












선택된 파일 없음


focalboard
playbooks
com.github.manland.mattermost-plugin-gitlab
