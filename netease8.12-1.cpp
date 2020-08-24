#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool func(vector<string> s) {
    sort(s.begin(), s.end());
    for (int i = 0; i < 6; ++i) {
        if (s[i][0] == s[i+1][0]) {
            return false;
        }
    }
    vector<int> w, t, b;
    for (int i = 0; i < 7; i++) {
        if (s[i][1] == 'T')
            t.push_back(s[i][0] - '0');
        else if (s[i][1] == 'W')
            w.push_back(s[i][0] - '0');
        else
            b.push_back(s[i][0] - '0');
    }
    for (int i = 0; i < t.size()-1; i++) {
        if (t[i+1] - t[i] != 3 && t[i+1] - t[i] != 6)
            return false;
    }
    for (int i = 0; i < w.size()-1; i++) {
        if (w[i+1] - w[i] != 3 && w[i+1] - w[i] != 6)
            return false;
    }
    for (int i = 0; i < b.size()-1; i++) {
        if (b[i+1] - b[i] != 3 && b[i+1] - b[i] != 6)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        vector<string> t(7);
        for (int i = 0; i < 7; i++) {
            cin >> t[i];
        }
        if (func(t))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}

