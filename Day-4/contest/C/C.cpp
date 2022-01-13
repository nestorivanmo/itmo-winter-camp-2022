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

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n; cin >> n;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> adj[i][j];
        }
    }
    vector<int> src, snk;
    vector<int> sources(n);
    for (int i = 0; i < n; i++) {
        bool is_sink = true;
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                is_sink = false;
                sources[j]++;
            }
        }
        if (is_sink) {
            snk.push_back(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (sources[i] == 0) {
            src.push_back(i);
        }
    }
    cout << src.size() << ' ';
    for (int i = 0; i < src.size(); i++) {
        cout << src[i]+1 << ' ';
    }
    cout << endl;
    cout << snk.size() << ' ';
    for (int i = 0; i < snk.size(); i++) {
        cout << snk[i]+1 << ' ';
    }
    cout << endl;
    return 0;
}
