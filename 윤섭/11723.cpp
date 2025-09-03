#include <iostream>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int M;
	cin >> M;
	
	int S = 0;

	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;

		int x;
        if (cmd == "add") {
            cin >> x;
            S |= (1 << (x - 1));
        }
        else if (cmd == "remove") {
            cin >> x;
            S &= ~(1 << (x - 1));
        }
        else if (cmd == "check") {
            cin >> x;
            cout << ((S & (1 << (x - 1))) ? 1 : 0) << "\n";
        }
        else if (cmd == "toggle") {
            cin >> x;
            S ^= (1 << (x - 1));
        }
        else if (cmd == "all") {
            S = (1 << 20) - 1;
        }
        else if (cmd == "empty") {
            S = 0;
        }
	}
}
