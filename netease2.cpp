#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> a;
    int n;
    int func(int n, vector<int> a) {
        this->a = a;
        this->n = n;
        int sum = 0;
        for (auto& i : a)
            sum += i;
        return sum - 2 * dfs(0, 0, 0);
    }

    int dfs(int index, int sum1, int sum2) {
        if (index == n) { 
            if (sum1 == sum2)
                return sum1;
            else
                return 0;
        }
        int temp = max(dfs(index+1, sum1+a[index], sum2), dfs(index+1, sum1, sum2+a[index]));
        return max(temp, dfs(index+1, sum1, sum2));
    }
};

int main() {
    Solution s;
    int n = 5;
    vector<int> a{ 30, 60, 5, 15, 30 };
    cout << s.func(n, a);
    
    return 0;
}