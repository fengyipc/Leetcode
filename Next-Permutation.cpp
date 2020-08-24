#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i >= 0) {
            int j = i + 1;
            while ((j + 1) < nums.size() && nums[j + 1] > nums[i])
                j++;
            swap(nums, i, j);
        }
        sort(nums.begin() + i + 1, nums.end());
    }
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};

int main() {
    Solution s;
    vector<int> nums{1, 2};
    s.nextPermutation(nums);
    for (auto i : nums)
        cout << i << ' ';
}