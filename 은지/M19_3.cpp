// [방법 1]
// ---------------------------------------------------------------
#include <iostream> 
using namespace std;

struct Point {
	int y, x;
};

int main() {

	char map[4][5] = {
		{'_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_'},
		{'_', '_', '_', '_', '_'},
	};

	// 8방향: 위, 아래, 왼, 오, 왼 위 대, 오 위 대, 왼 아 대, 오 아 대; 
	int dy[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
	int dx[8] = { 0, 0, -1, 1, -1,  1, -1, 1 };

	Point p1, p2;
	std::cin >> p1.y >> p1.x >> p2.y >> p2.x;
	
	for (int i = 0; i < 8; i++) {
		int ny = p1.y + dy[i];
		int nx = p1.x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 5) {
			continue;
		}

		map[ny][nx] = '#';
	}


	for (int i = 0; i < 8; i++) {
		int ny = p2.y + dy[i];
		int nx = p2.x + dx[i];

		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 5) {
			continue;
		}

		map[ny][nx] = '#';
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			std::cout << map[i][j] << " ";
		}

		std::cout << "\n";
	}

	return 0;
}
// ---------------------------------------------------------------


// [방법 2] : [방법 1]을 함수로 만듦
// ---------------------------------------------------------------
#include <iostream>
using namespace std;

char map[4][5];

//좌상, 상, 우상, 좌, 우, 좌하, 하, 우하
int dirY[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; 
int dirX[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void drop(int y, int x) {
	for (int t = 0; t < 8; t++) {
		int ny = y + dirY[t];
		int nx = x + dirX[t];

		if (ny < 0 || nx < 0 || ny >= 4 || nx >= 5) continue;
		map[ny][nx] = '#';
	}
}

int main() {
	int x, y;

	//'_'로 꽉 채우기
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 5; x++) {
			map[y][x] = '_';
		}
	}

	//폭탄 투하
	cin >> y >> x;
	drop(y, x);

	cin >> y >> x;
	drop(y, x);

	//출력
	for (y = 0; y < 4; y++) {
		for (x = 0; x < 5; x++) {
			cout << map[y][x] << " ";
		}
		cout << "\n";
	}

}
// ---------------------------------------------------------------
