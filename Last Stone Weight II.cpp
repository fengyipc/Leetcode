#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum;
        for (auto i = stones.begin(); i != stones.end(); ++i)
            sum += (*i) >> 1;
        vector<vector<int> > dp(stones.size(), vector<int>(sum + 1, 0));
        for (int i = 0; i <= sum; ++i) {
            if (stones[0] <= i)
                dp[0][i] = stones[0];
        }
        for (int i = 1; i < stones.size(); ++i) {
            for (int j = sum; j > 0; --j) {
                dp[i][j] = dp[i - 1][j];
                if (j > stones[i])
                    dp[i][j] =
                        max(dp[i][j], dp[i - 1][j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[stones.size() - 1][sum];
    }
};

int main() {
    Solution s;
    vector<int> t = {31, 26, 33, 21, 40};
    cout << s.lastStoneWeightII(t);
}