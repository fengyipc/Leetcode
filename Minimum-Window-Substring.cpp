#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window;
        unordered_map<char, int> target;
        for(auto i : t) {
            if (target.find(i) != target.end())
                target[i]++;
            else
                target[i] = 1;
        }
        int minleft = INT_MIN >> 2, minright = INT_MAX >> 2;
        int left = 0, right = 0;
        while(right <= s.size()) {
            if (window.size() != t.size()) {
                if (t.find(s[right++]) != t.npos) {
                    if(window.find(s[right-1]) != window.end())
                        window[s[right - 1]]++;
                    else
                        window[s[right - 1]] = 1;
                }
            } else {
                if (right-left < minright-minleft)
                    minright = right, minleft = left;
                if (window.find(s[left]) != window.end() && window[s[left]] != 1) {
                    window[s[left]] -= 1;
                } else if (window.find(s[left]) != window.end() && window[s[left]] == 1) {
                    window.erase(s[left]);
                }
                left++;
            }
        }
        if (minleft == INT_MIN >> 2)
            return "";
        return s.substr(minleft, minright-minleft);
    }
};

int main() {
    // Solution a;
    // string s = "A";
    // string t = "A";
    // cout << a.minWindow(s, t);

}