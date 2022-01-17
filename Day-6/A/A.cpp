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
    int n = (int)s.size();
    vector<int> pref(n); // prefix
    // Just one character
    pref[0] = 0;
    // Otherwise
    for (int i = 1; i < n; i++) {
        int x = pref[i-1];
        while (x > 0 && s[x] != s[i]) {
            x = pref[x-1];
        }
        if (s[i] == s[x]) {
            x++;
        }
        pref[i] = x;
    }
    for (int i = 0; i < n; i++) {
        cout << pref[i] << ' ';
    }
    return 0;
}
