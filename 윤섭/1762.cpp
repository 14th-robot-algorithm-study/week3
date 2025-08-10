#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct point {
    int y, x;
};

int N;
int map[12][12];
int coreNum;
point core[12];
int visited[12];
int maxCore;
int minDistance;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void func(int now, int totalDistance, int coreCnt) {
    // 모든 코어를 다 시도한 경우 결과 갱신
    if (now == coreNum) {
        if (coreCnt > maxCore || (coreCnt == maxCore && totalDistance < minDistance)) {
            maxCore = coreCnt;
            minDistance = totalDistance;
        }
        return;
    }

    // 가장자리에 있는 코어는 전선 필요 없음
    if (core[now].y == 0 || core[now].x == 0 || core[now].y == N - 1 || core[now].x == N - 1) {
        visited[now] = 1;
        func(now + 1, totalDistance, coreCnt + 1);
        visited[now] = 0;
        return;
    }

    // 4방향 시도
    for (int d = 0; d < 4; d++) {
        int currentY = core[now].y;
        int currentX = core[now].x;
        int currentWire[12][12] = { 0 };
        int distance = 0;
        int flag = 0;

        // 한 칸씩 전진
        while (true) {
            currentY += dy[d];
            currentX += dx[d];

            // 경계 도착 -> 성공
            if (currentY < 0 || currentX < 0 || currentY >= N || currentX >= N) break;

            // 장애물(코어 또는 전선) 만나면 실패
            if (map[currentY][currentX] == 1) {
                flag = 1;
                break;
            }

            // 전선 설치
            currentWire[currentY][currentX] = 1;
            distance++;
        }

        // 유효한 경로일 경우만 진행
        if (flag == 0) {
            visited[now] = 1;

            // 전선 반영
            for (int a = 0; a < N; a++) {
                for (int b = 0; b < N; b++) {
                    if (currentWire[a][b] == 1) map[a][b] = 1;
                }
            }

            func(now + 1, totalDistance + distance, coreCnt + 1);

            // 전선 제거
            for (int a = 0; a < N; a++){
                for (int b = 0; b < N; b++){
                    if (currentWire[a][b] == 1) map[a][b] = 0;
                }
            }

            visited[now] = 0;
        }
    }

    // 이 코어를 연결하지 않는 경우도 시도
    func(now + 1, totalDistance, coreCnt);
}

int main() {
    int T;

    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        memset(map, 0, sizeof(map));
        memset(core, 0, sizeof(core));
        memset(visited, 0, sizeof(visited));
        coreNum = 0;
        minDistance = 21e8;
        maxCore = 0;

        cin >> N;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> map[i][j];
                if (map[i][j] == 1) {
                    core[coreNum++] = { i, j };
                }
            }
        }

        func(0, 0, 0);
        cout << "#" << test_case << " " << minDistance << "\n";
    }
}
