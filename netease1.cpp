#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string func(string str) {
        string temp = str;
        reverse(temp.begin(), temp.end());
        int max = 0;
        for (int i = 0; i <= str.size(); i++)
        {
            if (str.substr(str.size() - i) == temp.substr(0, i))
                max = i;
        }
        cout << max <<endl;
        string temp2 = str.substr(0, str.size()-max);
        reverse(temp2.begin(), temp2.end());
        return str+temp2;
    }
};

int main() {
    Solution s;
    string a = "abcdba";
    cout << s.func(a);
    
    return 0;
}