#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}
class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        for (auto i = ++intervals.begin(); i != intervals.end(); ++i) {
            if ((*i)[0] < (*res.rbegin())[1])
                (*res.rbegin())[1] = max((*res.rbegin())[1], (*i)[1]);
            else
                res.push_back(*i);
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> internal{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = s.merge(internal);
    for (auto i : res)
        cout << "[ " << i[0] << ", " << i[1] << "]" << endl;
}