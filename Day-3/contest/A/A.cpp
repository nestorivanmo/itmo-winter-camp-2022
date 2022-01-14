#include <bits/stdc++.h>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r",  stdin);
    freopen(out_file.c_str(), "w",  stdout);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, m; cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> f(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) {
                f[i][j] = grid[i][j];
            } else if (i == 0) {
                f[i][j] = f[i][j-1] + grid[i][j];
            } else if (j == 0) {
                f[i][j] = f[i-1][j] + grid[i][j];
            } else {
                f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << f[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    cout << f[n-1][m-1] << endl;
    return 0;
}
