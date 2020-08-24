#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        for(auto i = s.begin(); i != s.end();) {
            if (isupper(*i)) {
                *i = tolower(*i);
                i++;
            } else if (isdigit(*i) || islower(*i))
                i++;
            else
                i = s.erase(i);
        }
        int i = 0, j = s.size()-1;
        cout << s <<endl;
        while(i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main() {
    Solution s;
    string a = "A man, a plan, a canal: Panama";
    if (s.isPalindrome(a))
        cout << "true";
    else
        cout << "false";
}
