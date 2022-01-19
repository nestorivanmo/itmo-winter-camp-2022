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

struct edge {
    int from, to, w;
};

int const INF = 1 << 30;
int const UNKNOWN = INF + 1;

int dfs(int v, int s, vector<vector<edge>> const & incoming, vector<int> &d) {
    if (v == s) {
        d[v] = 0;
        return d[v];
    }
    if (d[v] != UNKNOWN) {
        return d[v];
    }
    d[v] = INF;
    for (auto &last : incoming[v]) {
        int du = dfs(last.from, s, incoming, d);
        if (du != INF) {
            d[v] = min(d[v], du + last.w);
        }
    }
    return d[v];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s;
    --t;
    vector<vector<edge>> incoming(n);
    for (int i = 0; i < m; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        from--; to--;
        incoming[to].push_back({from, to, w});
    }
    vector<int> d(n, UNKNOWN);
    int ans = dfs(t, s, incoming, d);
    if (ans == INF) {
        cout << "Unreachable" << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
