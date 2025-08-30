#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cin >> text;

    for (char& c : text) {
        if (c >= 'A' && c <= 'Z') c = c - 'A' + 'a';
    }

    int count = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text.substr(i, 7) == "http://" || text.substr(i, 8) == "https://") {
            int start_len = (text.substr(i, 7) == "http://") ? 7 : 8;
            string endings[] = { ".com", ".co.kr", ".org", ".net" };
            
            for (string end : endings) {
                int flag = 0;
                if (text.find(end, i + start_len) != string::npos) {
                    int pos = text.find(end, i + start_len);
                    if (pos - i - start_len >= 3) count++;
                    flag = 1;
                    i = pos;
                    break;
                }
                if (flag == 1) break;
            }
        }
    }

    cout << count << "개\n";
    return 0;
}
