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
    vector<int> taken(51, 0); taken[0] = 1;
    int j = 0;
    while (j < s.size()) {
        int c = (int) s[j] - '0';
        if (c == 0) { j++; continue; }
        if (taken[c]) {
            string nn;
            nn += s[j];
            nn += s[j+1];
            c = stoi(nn);
            nn = "";
            j++;
        }
        taken[c] = 1;
        j++;
        cout << c << ' ';
    }
    cout << endl;

    
    // vector<int> p;
    // for (int i = 0; i < 50; i++) {
    //     p.push_back(i+1);
    // }
    // next_permutation(p.begin(), p.end());
    // for (auto o : p) {
    //     cout << o;
    // }
    return 0;
}
