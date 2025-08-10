#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int magnet[5][8];
int score[5] = { 0, 1, 2, 4, 8 };

void rotateMagnet(int num, int rotate) {
	int subMagnet[8];
	for (int i = 0; i < 8; i++) {
		subMagnet[i] = magnet[num][i];
	}

	if (rotate == 1) { // 시계방향 회전
		for (int i = 0; i < 8; i++) {
			magnet[num][(i + 1) % 8] = subMagnet[i];
		}
	}
	else if (rotate == -1) { // 반시계 방향 회전
		for (int i = 0; i < 8; i++) {
			magnet[num][i] = subMagnet[(i + 1) % 8];
		}
	}
}

int main()
{
	int test_case;
	int T;

	//freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int K;
		cin >> K;	// 자석을 회전시키는 횟수
		memset(magnet, 0, sizeof(magnet));	// 자석 초기화
		int totalScore = 0;	//점수 초기화

		for (int i = 1; i <= 4; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> magnet[i][j];
			}
		}

		int num, rotate;	// 자석 번호, 회전 방향

		/*=====     회전 구현     =====*/
		for (int i = 0; i < K; i++) {
			cin >> num >> rotate;

			int rotateDir[5] = { 0 };
			rotateDir[num] = rotate;

			/*=====     오른쪽 자석 회전 검사     =====*/ 
			for (int j = num; j < 4; j++) {
				if (magnet[j][2] != magnet[j + 1][6])
					rotateDir[j + 1] = -rotateDir[j];
				else
					break;
			}

			/*=====     왼쪽 자석 회전 검사     =====*/
			for (int j = num; j > 1; j--) {
				if (magnet[j][6] != magnet[j - 1][2])
					rotateDir[j - 1] = -rotateDir[j];
				else
					break;
			}

			/*=====     회전 적용     =====*/
			for (int j = 1; j <= 4; j++) {
				if (rotateDir[j] != 0) {
					rotateMagnet(j, rotateDir[j]);
				}
			}
		}

		/*=====     점수 획득 구현     =====*/
		for (int i = 1; i <= 4; i++) {
			if (magnet[i][0] == 1) totalScore += score[i];
		}

		cout << "#" << test_case << " " << totalScore << "\n";
	}
}
