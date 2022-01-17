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
    string s; cin >> s;
    int n = (int) s.size();
    vector<int> z(n);
    int l = 0; // largest block
    for (int i = 1; i < n; i++) {
        // calculate z[i]
        // 1. Consider z[i-l], cut it if necessary
        z[i] = min(z[i-l], max(0,l+z[l]-i));
        // 2. Extend naively
        while (i + z[i] < n && s[i+z[i]] == s[z[i]]) {
            z[i]++;
        }
        // 3. Update rightmost block
        if (i+z[i] > l + z[l]) {
            l = i;
        }
    }
    for (int i = 1; i < n; i++) {
        cout << z[i] << ' ';
    }
    return 0;
}
