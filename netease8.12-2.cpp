#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > FullCombo(vector<vector<int> > &Arr) {
    vector<vector<int>> res;
    int n = Arr.size()-1;
    vector<int> rowFlag(Arr.size(), 0);
    vector<int> colFlag(Arr.size(), 0);

    while(n--) {
        vector<int> row(Arr.size()), col(Arr.size());
        for (int i = 0; i < Arr.size(); i++) {
            for (int j = 0; j < Arr.size(); j++) {
                row[i] += Arr[i][j];
                col[j] += Arr[i][j];
            }
        }
        int max = -1, maxi = -1, maxj = -1;
        for (int i = 0; i < Arr.size(); i++) {
            for (int j = 0; j < Arr.size(); j++) {
                if (row[i] + col[j] - Arr[i][j] > max) {
                    maxi = i;
                    maxj = j;
                    max = row[i] + col[j] - Arr[i][j];
                }
            }
        }
        for (int i = 0; i < Arr.size(); i++) {
            Arr[i][maxj] = 0;
            Arr[maxi][i] = 0;
        }
        rowFlag[maxi] = 1;
        colFlag[maxj] = 1;
        int cutRow = 0, cutCol = 0;
        for (int i = 0; i < maxi; i++) {
            cutRow += rowFlag[i];
        }
        for (int i = 0; i < maxj; i++) {
            cutCol += colFlag[i];
        }
            res.push_back(vector<int>{maxi + 1 - cutRow, maxj + 1 - cutCol});
    }
    res.push_back(vector<int>{1, 1});
    return res;
}

int main() {
    vector<vector<int>> t = {{1, 0, 0},
                             {0, 10, 10},
                             {0, 10, 10}};
    vector<vector<int>> res = FullCombo(t);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << ' ' << res[i][1] << endl;
    }
    return 0;
}

