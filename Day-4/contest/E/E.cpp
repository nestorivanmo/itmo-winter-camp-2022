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

vector<vector<int>> adj;
vector<int> visited, component, representative;
int cc;

void dfs(int v, int r) {
    component.push_back(v);
    representative[v] = r;
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) dfs(u, r);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, m; cin >> n >> m;
    adj.resize(n);
    visited.assign(n, false);
    cc = 0;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    representative.assign(n, -1);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            component.clear();
            dfs(i, cc);
            cc++;
        }
    }
    cout << cc << endl;
    for (int i = 0; i < representative.size(); i++) {
        cout << representative[i]+1 << ' ';
    }

    return 0;
}