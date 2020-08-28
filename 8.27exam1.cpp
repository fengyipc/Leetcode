#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int GetNum(vector<int>& nums, int magic) {
    sort(nums.begin(), nums.end());
    int CurSum(0);
    for (int i = 1; i < nums.size(); i++) {
        CurSum += (nums[i] - nums[i - 1]) * i;
        if (CurSum > magic)
            return nums[i - 1];
    }
    return nums[nums.size() - 1];
}

int main() {
    int num, magic;
    vector<int> input;
    cin >> num >> magic;
    for (int i = 0; i < num; i++) {
        input.emplace_back();
        auto& back = input.back();
        cin >> back;
    }

    cout << GetNum(input, magic);
    return 0;
}