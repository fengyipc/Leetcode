#include <iostream>
#include <string>

using namespace std;
class Solution {
   public:
    string s;
    bool validPalindrome(string s) {
        this->s = s;
        return func(0, s.size() - 1, false);
    }
    bool func(int l, int r, bool del) {
        if (l >= r)
            return true;
        else if (s[l] == s[r])
            return func(++l, --r, del);
        else if (del)
            return false;
        else
            return func(l + 1, r, true) || func(l, r - 1, true);
    }
};

int main() {
    Solution s;
    string str = "abc";
    if (s.validPalindrome(str))
        cout << "True";
    else
        cout << "False";
}