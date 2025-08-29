#include <iostream>
#include <string>
using namespace std;

string path[3]; 

void dfs(int depth, int win, int lose) {
    if (depth == 3) { 
        if (win == 3) {
            cout << "3승(";
        }
        else if (lose == 3) {
            cout << "3패(";
        }
        else {
            cout << win << "승" << lose << "패(";
        }
        for (int i = 0; i < 3; i++) cout << path[i];
        cout << ")" << endl;
        return;
    }

    path[depth] = "승";
    dfs(depth + 1, win + 1, lose);

    path[depth] = "패";
    dfs(depth + 1, win, lose + 1);
}

int main() {
    dfs(0, 0, 0);
    return 0;
}
