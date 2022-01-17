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

long long h(string s, long long t, long long r) {
    long long hash_value = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int a = (int) s[i];
        hash_value = (hash_value + (long long) (a * pow(t, n-i-1))) % r;
    }
    return hash_value % r;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    long long t, r;
    cin >> t >> r;
    string s; cin >> s;
    string p = "";
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        p += s[j];
        cout << h(p, t, r) << endl;
        j++;
    }
    return 0;
}
