#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int x[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int count = 0;

    bool inMap(int i, int j, int r, int c) {
        return (i >= 0)&&(i < r) && (j >= 0) && (j < c);
    } 
    void walk(int i, int j, vector<vector<char>>& grid) {
        if (inMap(i, j, grid.size(), grid[0].size()) && grid[i][j] == '1') {
            grid[i][j] = '#';
            for(int c = 0; c < 4; ++c)
                walk(i+x[c][0], j+x[c][1], grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    walk(i, j, grid);
                }
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    vector<vector<char>> a;
    a.push_back(vector<char>{'1', '1', '0', '0', '0'});
    a.push_back(vector<char>{'1', '1', '0', '0', '0'});
    a.push_back(vector<char>{'0', '0', '1', '0', '0'});
    a.push_back(vector<char>{'0', '0', '0', '1', '1'});
    cout << s.numIslands(a);
}