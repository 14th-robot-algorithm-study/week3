#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
using namespace std;
 
 
int arr[17][17];
int visited[17];
int min_val, cost;
int N;
bool flag = false;
void func(int n, int idx) {
    cost = 0;
    if (!min_val)flag = true;
    if (n == N / 2) {
        for (int i = 0; i < N - 1; i++)
        {
            for (int j = i+1; j < N; j++)
            {
                if (i == j)continue;
                if (visited[i] && visited[j]) {
                    cost += arr[i][j] + arr[j][i];
                }
                if (!visited[i] && !visited[j]) {
                    cost -= arr[i][j] + arr[j][i];
                }
            }
        }
        if (min_val > abs(cost))
            min_val = abs(cost);
 
        return;
    }
     
 
    for (int i = idx; i < N; i++)
    {
        if (flag) return;
        if (visited[i])continue;
        visited[i] = 1;
        func(n + 1, i+1);
        visited[i] = 0;
    }
 
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
     
    for (test_case = 1; test_case <= T; ++test_case)
    {
        min_val = 2e8;
        cin >> N;
        flag = false;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> arr[i][j];
            }
        }
        func(0,0);
        cout <<"#"<<test_case << " " << min_val << '\n';
 
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}