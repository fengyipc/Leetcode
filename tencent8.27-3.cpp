#include <iostream>
#include <string>

using namespace std;

int main() {
    string str, res;
    cin >> str;
    int set[52] = {0};
    for (auto c : str) {
        if (isupper(c))
            set[(c - 'A') * 2]++;
        else
            set[(c - 'a') * 2 + 1]++;
    }
    for (int i = 0; i < 52; ++i) {
        char c = (i % 2) ? i / 2 + 'a' : i / 2 + 'A';
        res += string(set[i], c);
    }
    cout << res;
    return 0;
}