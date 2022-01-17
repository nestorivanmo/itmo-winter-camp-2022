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

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    string s; cin >> s;
    int n = (int) s.size();
    auto z = z_function(s);
    // for (int i = 0; i < z.size(); i++) {
    //     cout << z[i] << ' ';
    // }
    // cout << endl;
    int ans = n;
    for (int j = 0; j < n-1; j++) {
        // if ((z[j+1] + j + 1 == n) && (z[j+1] % (j+1) == 0)) {
        //     ans = min(ans, z[j+1]/(j+1) + 1);
        // }
        if (z[j]+j==n && n%j == 0) {
            ans = j;
            break;
        }
    }    
    cout << ans << endl;
    return 0;
}
