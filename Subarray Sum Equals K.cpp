#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        map<int, int> t;
        int pre = 0;
        t[0]++;
        res += t[nums[0] - k];
        for (int i = 1; i < nums.size(); ++i) {
            pre += nums[i - 1];
            t[pre]++;
            res += t[pre + nums[i] - k];
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1, 1, 1};
    int k = 2;
    cout << s.subarraySum(nums, k);
}