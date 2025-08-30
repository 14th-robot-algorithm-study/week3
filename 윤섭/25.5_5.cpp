#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    string name = "";
    string number = "";

    for (char c : s) {
        if (isalpha(c)) {
            if (!number.empty()) {
                int num = stoi(number) + 17;
                cout << name << "#" << num << "\n";
                number = "";
                name = "";
            }
            name += c; 
        }
        else if (isdigit(c)) {
            number += c; 
        }
    }

    if (!name.empty() && !number.empty()) {
        int num = stoi(number) + 17;
        cout << name << "#" << num << "\n";
    }

    return 0;
}
