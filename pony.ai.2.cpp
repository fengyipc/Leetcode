#include <iostream>
#include <vector>

using namespace std;

int func(int n, int v1, int v2, int v3, int v4) {
    vector<int> dp(n + 1, INT_MAX >> 1);
    dp[0] = 0;
    bool change;
    do {
        change = false;
        for (int i = 1; i <= n; ++i) {
            int t1 = dp[i - 1] + v4;
            int t2 = (i < n) ? dp[i + 1] + v3 : INT_MAX >> 1;
            int t3 = (i % 2 == 0) ? dp[i / 2] + v2 : INT_MAX >> 1;
            int t4 = (i % 3 == 0) ? dp[i / 3] + v1 : INT_MAX >> 1;
            int temp = dp[i];
            dp[i] = min(min(min(min(dp[i], t1), t2), t3), t4);
            if (dp[i] != temp)
                change = true;
        }
    } while (change);

    return dp[n];
}

int main() {
    cout << func(1, 1, 1, 1, 10000) << endl;
    cout << func(2, 10, 1000, 1, 10000) << endl;
    cout << func(13, 1, 1, 1, 1) << endl;
    cout << func(100, 1, 1, 1, 1) << endl;
    cout << func(256, 1, 1, 1, 1) << endl;
    cout << func(256, 1, 2, 1, 1) << endl;
    cout << func(114514, 1, 1, 1, 1) << endl;
    // cout << func(1000000000, 1000000000, 1000000000, 1000000000, 1000000000)
    //      << endl;
}