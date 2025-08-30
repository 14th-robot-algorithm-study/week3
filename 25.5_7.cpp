#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        int flag = 0;             // 조건 위반 체크
        int visited[200] = { 0 };   // 알파벳 사용 횟수
        int cnt = 0;              // 모음 개수

        for (char c : name) {
            if (!(c >= 'a' && c <= 'z')) { // 소문자 아닌 경우
                flag = 1;
                break;
            }

            visited[(int)c]++;
            if (visited[(int)c] >= 3) {  // 같은 글자 2개 초과
                flag = 1;
                break;
            }

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
        }

        if (flag == 0 && cnt == 3) cout << "good\n";
        else cout << "no\n";
    }
    return 0;
}
