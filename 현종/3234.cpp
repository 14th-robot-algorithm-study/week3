#include<iostream>
#include <cmath>
using namespace std;
 
int N;
int w[10];
int visited[1000];
int put[10][2];
int w_l, w_r, w_total;
int cnt;
int flag;
 
int factorial(int n) {
    if (n == 1)return 1;
    return n * (factorial(n - 1));
}
void func(int n, int dir) {
    if (w_l < w_r)return;
     
    if (n == N) {
        cnt++;
        return;
    }
 
    for (int i = 0; i < N; i++)
    {
        if (visited[i])continue;
        if (w_l > (w_total - w_l)) {
            cnt += factorial(N - n) * pow(2, N - n);
            return;
        }
        visited[i] = 1;
        w_l += w[i];
        func(n + 1,0);
        w_l -= w[i];
        w_r += w[i];
        func(n + 1,1);
        w_r -= w[i];
        visited[i] = 0;
    }
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    //freopen("input.txt", "r", stdin);
    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        cnt = 0, w_total = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> w[i];
            w_total += w[i];
        }
 
        func(0, 0);
 
        cout << "#"<<test_case<<" "<<cnt << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}