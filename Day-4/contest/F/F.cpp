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

// Directed graph only
int n, m;
vector<vector<int>> adj;
vector<int> color, parent;
int cycle_start, cycle_end;

bool DFS(int v) { // modified DFS that checks if a cycle exists
    color[v] = 1; // Visited
    for (auto u : adj[v]) {
        if (color[u] == 0) { // Not visited
            parent[u] = v;
            if (DFS(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2; // Exited
    return false;
}

void FindCycle() {
    color.assign(n, 0);
    parent.assign(n, -1);
    cycle_start = -1;

    for (int v = 0; v < n; v++)
        if (color[v] == 0 && DFS(v))
            break;

    if (cycle_start == -1) {
        cout << "NO" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_end);
        auto curr_node = parent[cycle_end];
        while (curr_node != cycle_start) {
            cycle.push_back(curr_node);
            curr_node = parent[curr_node];
        }
        cycle.push_back(cycle_start);
        // reverse(cycle.begin(), cycle.end());
        cout << "YES" << endl;
        for (auto u : cycle) cout << u+1 << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[v].push_back(u);
    }
    FindCycle();
    return 0;
}
