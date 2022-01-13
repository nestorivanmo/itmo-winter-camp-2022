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

vector<bool> visited;
vector<vector<int>> adj_list;
void dfs(int v) {
    visited[v] = true;
    for (auto u : adj_list[v]) {
        if(!visited[u]) dfs(u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n; cin >> n;
    set<pair<int,int>> edges;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    adj_list.resize(n);
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
            if (adj[i][j] == 1) {
                int a = max(i,j);
                int b = min(i,j);
                edges.insert({a,b});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                adj_list[i].push_back(j);
            }
        }
    }

    int cc = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            cc++;
        }
    }
    
    if (cc > 1) {
        cout << "NO" << endl;
        return 0;
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j && adj[i][j] == 1) || (adj[i][j] != adj[j][i])) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    
    if (edges.size() == n-1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
