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
    map<int, int> m_a;
    for (int i = 0; i < n; i++) {
        int u; cin >> u;
        if (m_a.find(u) == m_a.end()) {
            m_a[u] = 1;
        } else {
            m_a[u]++;
        }
    }

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int u; cin >> u;
        if (m_a.find(u) == m_a.end()) {
            cout << 0 << endl;
        } else {
            cout << m_a[u] << endl;
        }
    }
    return 0;
}
