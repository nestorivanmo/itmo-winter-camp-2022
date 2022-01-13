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

vector<vector<int>> adj, adj_mat;
vector<int> ts, color;

#define INF 1e10

void dfs(int v) {
    color[v] = 1;
    for (auto u : adj[v]) {
        if (color[u] == 0) {
            dfs(u);
        } 
    }
    color[v] = 2;
    ts.push_back(v);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    s--; t--;
    adj.resize(n);
    adj_mat.resize(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back(v);
        adj_mat[u][v] = w;
    }
    color.assign(n, 0);
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i);
        }
    }
    reverse(ts.begin(), ts.end());

    // for (int i = 0; i < ts.size(); i++) {
    //     cout << ts[i]+1 << ' ';
    // }
    // cout << endl;

    vector<long long> d(n, INF);
    d[s] = 0;
    for (auto u : ts) {
        for (auto v : adj[u]) {
            if (d[v] > d[u] + adj_mat[u][v]) {
                d[v] = d[u] + adj_mat[u][v];
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     cout << d[i] << ' ';
    // }
    // cout << endl;

    if (d[t] == INF) {
        cout << "Unreachable" << endl;
    } else {
        cout << d[t] << endl;
    }
    return 0;
}