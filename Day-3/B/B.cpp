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
    vector<int> a(n); 
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> f(n), g(n, -1);
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && f[i] < f[j]+1) {
                f[i] = f[j] + 1;
                g[i] = j;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cerr << i << ' ';
    }
    cerr << endl;
    for (int i = 0; i < n; i++) {
        cerr << a[i] << ' ';
    }
    cerr << endl;
    for (int i = 0; i < n; i++) {
        cerr << f[i] << ' ';
    }
    cerr << endl;
    for (int i = 0; i < n; i++) {
        cerr << g[i] << ' ';
    }
    cerr << endl;

    int ans = -1;
    int p = -1;
    for (int i = 0; i < n; i++) {
        if (f[i] > ans) {
            ans = f[i];
            p = i;
        }
    }
    cerr << "ans=" << ans << " p=" << p << endl;
    cout << ans << endl;
    vector<int> r;
    while (p > -1) {
        cerr << "p=" << p << endl;
        r.push_back(a[p]);
        p = g[p];
    }
    reverse(r.begin(), r.end());
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << ' ';
    }


    return 0;
}
