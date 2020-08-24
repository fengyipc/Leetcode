#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct mypair {
    string first;
    int second;
    mypair(string f, int s) : first(f), second(s) {}
    bool operator<(const mypair& b) const {
        if (second == b.second)
            return first < b.first;
        return second < b.second;
    }
};

class Solution {
   public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> res;
        map<string, int> set;
        for (auto i : words)
            set[i]++;
        priority_queue<mypair> heap;

        for (auto i : set) {
            if (heap.size() == k && mypair(i.first, i.second) < heap.top()) {
                heap.pop();
                heap.push(mypair(i.first, i.second));
            } else
                heap.push(mypair(i.first, i.second));
        }
        while (!heap.empty()) {
            res.push_back(heap.top().first);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    Solution s;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;
    vector<string> res = s.topKFrequent(words, k);
    for (auto i : res)
        cout << i << endl;
}