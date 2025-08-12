#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct point {
    int x, y;
};

struct AP {
    int x, y, C, P;
};

int maxSum;
int M, A;
int dx[5] = { 0, 0, 1, 0, -1 };
int dy[5] = { 0, -1, 0, 1, 0 };
int map[11][11];
int AMove[100];
int BMove[100];
AP APs[8];
int visitedA[8];
int visitedB[8];
int totalSum;

bool compareC(AP a, AP b) {
    return a.C > b.C;
}

int main()
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> M >> A;
        point A_point = { 1, 1 };
        point B_point = { 10, 10 };

        memset(AMove, 0, sizeof(AMove));
        memset(BMove, 0, sizeof(BMove));
        memset(APs, 0, sizeof(APs));
        totalSum = 0;

        for (int i = 0; i < M; i++) {
            cin >> AMove[i];
        }
        for (int i = 0; i < M; i++) {
            cin >> BMove[i];
        }
        for (int i = 0; i < A; i++) {
            cin >> APs[i].x >> APs[i].y >> APs[i].C >> APs[i].P;
        }

        sort(APs, APs + A, compareC);

        // ===== 움직임 구현 =====
        for (int i = 0; i <= M; i++) {
            memset(visitedA, 0, sizeof(visitedA));
            memset(visitedB, 0, sizeof(visitedB));

            // A, B의 현재 위치에서 접근 가능한 AP 체크
            for (int j = 0; j < A; j++) {
                if (abs(A_point.x - APs[j].x) + abs(A_point.y - APs[j].y) <= APs[j].C)
                    visitedA[j] = 1;

                if (abs(B_point.x - APs[j].x) + abs(B_point.y - APs[j].y) <= APs[j].C)
                    visitedB[j] = 1;
            }

            // 완전 탐색으로 A, B의 최대 충전량 구하기
            int maxCharge = 0;
            for (int a = 0; a < A; a++) {
                if (!visitedA[a]) continue;
                for (int b = 0; b < A; b++) {
                    if (!visitedB[b]) continue;

                    if (a == b) maxCharge = max(maxCharge, APs[a].P);
                    else maxCharge = max(maxCharge, APs[a].P + APs[b].P);
                }
            }

            // A만 사용 가능한 경우
            for (int a = 0; a < A; a++) {
                if (visitedA[a] == 1) maxCharge = max(maxCharge, APs[a].P);
            }

            // B만 사용 가능한 경우
            for (int b = 0; b < A; b++) {
                if (visitedB[b] == 1) maxCharge = max(maxCharge, APs[b].P);
            }

            totalSum += maxCharge;

            // 다음 위치로 이동
            if (i < M) {
                A_point.x += dx[AMove[i]];
                A_point.y += dy[AMove[i]];
                B_point.x += dx[BMove[i]];
                B_point.y += dy[BMove[i]];
            }
        }

        cout << "#" << test_case << " " << totalSum << "\n";
    }
    return 0;
}
