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

int root;
vector<int> f, g, w;
vector<vector<int>> adj;

void dfs(int v, int p) {
    f[v] = w[v];
    g[v] = 0;
    for (auto u : adj[v]) {
        if (u != p) {
            dfs(u, v);
            f[v] = f[v] + g[u];
            g[v] = g[v] + max(g[u], f[u]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n; cin >> n;
    f.resize(n);
    g.resize(n);
    w.resize(n);
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int p, q; cin >> p >> q;
        if (p == 0) {
            root = i;
        } else {
            p--;
            adj[p].push_back(i);
        }
        w[i] = q;
    }
    dfs(root, root);
    cout << max(f[root], g[root]) << endl;
    return 0;
}
