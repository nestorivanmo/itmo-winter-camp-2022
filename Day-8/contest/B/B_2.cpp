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

void topsort(int v, vector<int> &result, vector<vector<edge>> const &incoming, vector<int> &visited) {
    visited[v] = true;
    for (auto &e : incoming[v]) {
        if (!visited[e.from]) {
            topsort(e.from, result, incoming, visited);
        }
    }
    result.push_back(v);
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
        incoming[to].push_back({from, to, w});
    }
    vector<int> order;
    vector<int> visited(n);
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topsort(i, order, incoming, visited);
        }
    }
    vector<int> d(n, INF);
    d[s] = 0;
    for (auto v: order) {
        for (auto &e : incoming[v]) {
            if (d[e.from] != INF) {
                d[v] = min(d[v], d[e.from]+e.w);
            }
        }
    }
    if (d[t] == INF) {
        cout << "Unreachable" << endl;
    } else {
        cout << d[t] << endl;
    }
    return 0;
}
