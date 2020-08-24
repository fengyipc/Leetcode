#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int target;
    vector<int> searchRange(vector<int>& nums, int target) {
        if (!nums.size())
            return vector<int>{-1, -1};
        this->target = target;
        return vector<int>{searchLeft(nums), searchRight(nums)};
    }
    int searchLeft(vector<int>& nums) {
        int m;
        int l = 0, r = nums.size();
        while (l < r) {
            m = ((r - l) >> 1) + l;
            if (nums[m] == target)
                r = m;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        if (nums[l] == target)
            return l;
        else
            return -1;
    }
    int searchRight(vector<int>& nums) {
        int m;
        int l = 0, r = nums.size();
        while (l < r) {
            m = ((r - l) >> 1) + l;
            if (nums[m] == target)
                l = m + 1;
            else if (nums[m] < target)
                l = m + 1;
            else
                r = m;
        }
        if (nums[r - 1] == target)
            return r - 1;
        else
            return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> res = s.searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << endl;
}