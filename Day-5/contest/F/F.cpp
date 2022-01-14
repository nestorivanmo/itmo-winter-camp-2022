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

struct Vertex {
    int d, id;
};

bool operator < (const Vertex& a, const Vertex& b) {
    if (a.d == b.d) {
        return a.id - b.id;
    }
    return a.d < b.d;
}

struct Edge {
    int u, v, w;  
};

int n, m;
vector<vector<Edge>> adj;

#define INF 100000

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({v, u, w});
        adj[v].push_back({u, v, w});
    }

    vector<Vertex> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = {i, INF};
    }
    d[0].d = 0;

    set<Vertex> s;
    for (int i = 0; i < n; i++) {
        s.insert(d[i]);
    }

    for (int i = 0; i < n; i++) {
        auto v = s.begin();
        for (auto e : adj[v->id]) {
            int u = e.u;
            int weight = e.w;
            if (d[u].d > v->d + weight) {
                s.erase(v);
                d[u].d = v->d + weight;
                s.insert(d[u]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << d[i].d << ' ';
    }
    
    return 0;
}
