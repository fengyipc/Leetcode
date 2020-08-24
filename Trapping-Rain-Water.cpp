#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0;
        vector<int> maxL(height.size()), maxR(height.size());
        maxL[0] = height[0];
        maxL[height.size() - 1] = height[height.size() - 1];
        for(int i = 1; i < height.size(); ++i) {
            maxL[i] = max(maxL[i-1], height[i]);
            maxR[height.size() - i - 1] = max(maxR[height.size() - i], height[height.size() - i - 1]);
        }
        for(int i = 0; i < height.size(); ++i) {
            res += min(maxL[i], maxR[i]) - height[i];
        }
        return res;
    }
        
};

int main() {
    Solution s;
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << s.trap(a);
}