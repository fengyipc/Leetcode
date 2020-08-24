#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
   public:
    // 使用堆
    struct compare1 {
        bool operator()(vector<int>& a, vector<int>& b) { return a[1] > b[1]; }
    };
    int minMeetingRooms1(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, compare1> q;
        priority_queue<int, vector<int>, greater<int>> meeting;
        for (auto i : intervals)
            q.push(i);
        while (!q.empty()) {
            if (meeting.empty() || meeting.top() > q.top()[0])
                meeting.push(q.top()[1]);
            else {
                vector<int> temp;
                while (!meeting.empty() && meeting.top() <= q.top()[0]) {
                    temp.push_back(meeting.top());
                    meeting.pop();
                }
                *temp.rbegin() = q.top()[1];
                for (auto i : temp)
                    meeting.push(i);
            }
            q.pop();
        }
        return meeting.size();
    }

    // 时间轴 上车/下车算法
    static bool compare2(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
    int minMeetingRooms2(vector<vector<int>>& intervals) {
        int roomNums = 0;
        int maxNums = 0;
        vector<pair<int, int>> timestamp;
        for (auto i : intervals) {
            timestamp.push_back(pair<int, int>{i[0], 1});
            timestamp.push_back(pair<int, int>{i[1], -1});
        }
        sort(timestamp.begin(), timestamp.end(), compare2);
        for (auto i : timestamp)
            cout << i.first << ", " << i.second << endl;
        for (auto i = timestamp.begin(); i != timestamp.end(); ++i) {
            roomNums += i->second;
            maxNums = max(maxNums, roomNums);
        }
        return maxNums;
    }
};

int main() {
    Solution s;
    vector<vector<int>> i = {{15, 16}, {10, 15}, {16, 25}};
    cout << s.minMeetingRooms2(i);
}