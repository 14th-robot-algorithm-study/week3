#include <iostream>
#include <string>
using namespace std;

int count_possible(string s, int low, int high) {
    int count = 0;
    for (int i = low; i <= high; i++) {
        string num = to_string(i);
        if (num.length() != s.length()) continue; 
        bool ok = true;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] != 'X' && s[j] != num[j]) {
                ok = false;
                break;
            }
        }
        if (ok) count++;
    }
    return count;
}

int main() {
    string text;
    cin >> text;

    size_t first_dot = text.find('.');
    size_t second_dot = text.find('.', first_dot + 1);

    string year_str = text.substr(0, first_dot); 
    string month_str = text.substr(first_dot + 1, second_dot - first_dot - 1);
    string day_str = text.substr(second_dot + 1);

    int month_count = count_possible(month_str, 1, 12);
    int day_count = count_possible(day_str, 1, 31);

    int ans = month_count * day_count;
    cout << ans << "\n";

    return 0;
}
