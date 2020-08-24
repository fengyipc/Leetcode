#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

string func(string a, int k) {
    stack<char> st;
    int index = 0;
    while (k != 0 && index != a.size()) {
        if (st.empty() || a[index] >= st.top()) {
            st.push(a[index]);
            index++;
        } else {
            st.pop();
            k--;
        }
    }
    string res;
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    if (k == 0 && index != a.size())
        res += a.substr(index);
    if (k != 0)
        res = res.substr(0, res.size() - k);
    while (res[0] == '0')
        res = res.substr(1);
    if (res.empty())
        return string("0");
    return res;
}

int main() {
    string a = "100";
    int k = 1;
    cout << func(a, k);
}