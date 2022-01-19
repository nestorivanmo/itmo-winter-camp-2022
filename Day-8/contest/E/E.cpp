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

int const INF = 1<<30;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n; cin >> n;
    vector<vector<int>> lengths(n, vector<int>(n));
    for (auto &f : lengths) {
        for (auto &e : f) {
            cin >> e;
        }
    }
    vector<vector<int>> f(n, vector<int>(1 << n));
    vector<vector<int>> pre_last(n, vector<int>(1 << n));
    for (int A = 1; A < (1<<n); A++) {
        if ((A & (A-1)) == 0) { // the set of size 1
            int i = 0;
            while ((1 << i) != A) ++i;
            f[i][A] = 0;
        }  else {
            for (int v = 0; v < n; v++) {
                if (((A >> v) & 1) == 1) { // v is not in A
                    continue;
                } 
                int best = INF;
                int best_last = -1;
                for (int u = 0; u < n; u++) {
                    if (u == v || ((A >> u) & 1) == 0) { // u = v or u is not in A
                        continue;
                    }
                    int curr_path = f[u][A & ~(1 << v) + lengths[u][v]];
                    if (best > curr_path) {
                        best = curr_path;
                        best_last = u;
                    }
                    best = min(best, f[u][A & ~(1 << v) + lengths[u][v]]);
                }
                f[v][A] = best;
            }
        }
    }
    int ans = INF;
    int best_last = -1;
    for (int i = 0; i < n; i++) {
        if (ans > f[i][(1<<n)-1]) {
            ans = f[i][(1<<n)-1];
            best_last = i;
        }
        ans = min(ans, f[i][(1<<n)-1]);
    }
    cout << ans << endl;
    // Restore path
    vector<int> path;
    for (int A = (1<<n)-1, i = best_last; A > 0; A--) {
        path.push_back(i);
        int prev = pre_last[i][A];
        A &= ~(1<<i);
    }
    for (auto p : path) {
        cout << p << ' ';
    }
    cout << endl;
    return 0;
}
