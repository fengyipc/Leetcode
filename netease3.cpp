#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> a;
    vector<int> b;
    string func(int n, vector<int> a, vector<int> b) {
        this->a = a;
        this->b = b;
        return f2(f1(n-1));

    }
    int f1(int n) {
        if (n == 0)
            return a[0];
        if (n == 1)
            return min(a[0]+a[1], b[0]);
        return min(f1(n-1)+a[n], f1(n-2)+b[n-1]);
    }
    string f2(int t) {
        t+= 8 * 60 * 60;
        string res = "00:00:00 am";
        if (t > 12 * 60 * 60) { 
            res[9] = 'p';
            t -= 12 * 60 * 60;
        }
        int hour = t / 3600;
        res[1] = to_string(hour%10)[0];
        res[0] = to_string(hour/10)[0];

        int min = (t % 3600) / 60;
        res[4] = to_string(min%10)[0];
        res[3] = to_string(min/10)[0];

        int sec = t % 60;
        res[7] = to_string(sec%10)[0];
        res[6] = to_string(sec/10)[0];

        return res;
    }
};

int main() {
    Solution s;
    int n = 1;
    vector<int> a{ 8 };
    vector<int> b{ };
    cout << s.func(n, a, b);
    
    return 0;
}