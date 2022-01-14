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

#define INF -1

vector<vector<int>> adj;
vector<int> d;
int n;

void bfs(int x) {
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        auto v = q.front(); q.pop();
        for (int u = 0; u < n; u++) {
            if (adj[v][u] == 1) {
                if (d[u] == INF) {
                    d[u] = d[v] + 1;
                    q.push(u);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int x;
    cin >> n >> x;
    x--;
    adj.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    d.assign(n, INF);
    d[x] = 0;
    bfs(x);
    for (int i = 0; i < n; i++) {
        cout << d[i] << ' ';
    }
    return 0;
}
