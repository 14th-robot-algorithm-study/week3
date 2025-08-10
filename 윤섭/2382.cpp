#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K; //셀의 개수, 격리 시간, 미생물 군집의 개수

struct micro {
	int y, x; // 미생물 세로 가로 위치
	int num; // 미생물 수
	int dir; //이동방향
	int alive = 1; // 1은 살아있는 미생물 군집, 0은 죽어있는 미생물 군집
};

int dy[5] = { 0, -1, 1, 0, 0 };
int dx[5] = { 0, 0, 0, -1, 1 };

vector<micro> v;
int map[100][100];

int main()
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		v.clear(); // 벡터 초기화

		cin >> N >> M >> K;
		for (int i = 0; i < K; i++) {
			micro temp;
			cin >> temp.y >> temp.x >> temp.num >> temp.dir;
			map[temp.y][temp.x]++;	//	해당 좌표의 미생물 군집 개수
			v.push_back(temp);
		}

		/*=====     미생물 움직임 구현     =====*/
		for (int t = 0; t< M; t++){				//	M 시간 동안 미생물 움직임
			for (int i = 0; i < K; i++) {
				if (v[i].alive == 0) continue; //	죽은 군집은 패스
				map[v[i].y][v[i].x]--;	// 이동으로 인한 미생물 군집 개수 감소
				
				v[i].y += dy[v[i].dir];
				v[i].x += dx[v[i].dir];

				map[v[i].y][v[i].x]--;	// 이동으로 인한 미생물 군집 개수 증가

				if (v[i].y == 0 || v[i].x == 0 || v[i].y == N - 1 || v[i].x == N - 1) {	//	가장 자리의 셀로 이동 시
					if (v[i].dir % 2 == 1) v[i].dir++;
					else if (v[i].dir % 2 == 0) v[i].dir--;

					v[i].num /= 2;
				}
			}

			/*=====     미생물 충돌 구현     =====*/
			for (int i = 0; i < K; i++) {
				if (v[i].alive == 0) continue; // 죽은 군집은 패스
				if (map[v[i].y][v[i].x] == 1) continue;	// 해당 좌표에 혼자 있을 때 패스
				
				int maxNum = v[i].num;		
				int totalNum = v[i].num;
				int maxDir = v[i].dir;
				for (int j = i + 1; j < K; j++) {	//해당 군집 다음부터 탐색
					if (v[j].alive == 0) continue; // 죽은 군집은 패스
					if (v[i].y == v[j].y && v[i].x == v[j].x) {
						if (maxNum < v[j].num) {
							maxNum = v[j].num;
							maxDir = v[j].dir;
						}
						totalNum += v[j].num;
						v[j].alive = 0;	// 첫번째 군집으로 합체
					}
				}
				v[i].dir = maxDir;		// 가장 미생물이 많은 군집의 방향으로 변경
				v[i].num = totalNum;	// 미생물 수 합체
			}
		}
		
		int liveTotalNum = 0;
		for (int i = 0; i < K; i++) {
			if (v[i].alive == 0) continue; // 죽은 군집은 패스
			liveTotalNum += v[i].num;
		}


		cout << "#" << test_case << " " << liveTotalNum <<"\n";

	}
	return 0;
}
