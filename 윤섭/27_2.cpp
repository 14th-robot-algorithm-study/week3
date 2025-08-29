#include <iostream>
using namespace std;

int main() {
    int mat[4][4];
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> mat[i][j];
        }
    }

    int maxCnt = -1, idx = 0;
    for (int i = 0; i < 4; i++) {
        int cnt = 0;
        for (int j = 0; j < 4; j++) {
            if (mat[i][j] == 1) cnt++;
        }
        if (cnt > maxCnt) {
            maxCnt = cnt;
            idx = i;
        }
    }

    cout << char('A' + idx) << endl;

    return 0;
}
