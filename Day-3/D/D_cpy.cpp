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

void debug_f(vector<vector<int>> f) {
    for (int i = 0; i < f.size(); i++) {
        for (int j = 0; j < f[0].size(); j++) {
            cerr << f[i][j] << ' ';
        }
        cerr << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, W; cin >> n >> W;
    vector<int> w(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    vector<vector<int>> f(n+1, vector<int> (W+1, -1000000));
    for (int i = 0; i <= n; i++) {
        f[i][0] = 0;
    }
    
    for(int i = 1; i <= n; i++) {
        f[i][w[i-1]] = c[i-1];
        for (int k = 0; k <= W; k++) {
            f[i][k] = f[i-1][k];
            if (k >= w[i-1]) {
                f[i][k] = max(f[i-1][k], f[i-1][k-w[i-1]] + c[i-1]);
            }
        }
    }

    debug_f(f);

    int p = -1;
    int curr_k = -1;
    for (int k = 0; k <= W; k++) {
        if (f[n][k] > p) {
            p = f[n][k];
            curr_k = k;
        }
    }

    vector<int> ans;
    for (int i = n; i > 0 && p > 0; i--) {
        if (f[i-1][curr_k] == p) {
            continue;
        } else {
            ans.push_back(i);
            p -= c[i-1];
            curr_k -= w[i-1];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (auto c : ans) {
        cout << c << ' ';
    }
    cout << endl;

    return 0;
}
