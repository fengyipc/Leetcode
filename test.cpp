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
    int a, b;
    cin >> a >> b;
    int res = b;
    (a > b) && (res = a);

    // int x = a - b;
    // res = a - (x) & (x >> 31);
    unsigned int x = -1;
    cout << (x >> 31);
    return 0;
}
