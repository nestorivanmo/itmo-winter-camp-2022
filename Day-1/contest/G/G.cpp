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

    if (n == 1) {
        int a; cin >> a;
        if (a == 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
        return 0;
    }

    vector<int> nums;
    vector<int> count(n-1, 0);
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        nums.push_back(a);
        count[a]++;
    }

    // for (auto c : count) {
    //     cout << c << ' ';
    // }
    // cout << endl;



    int max_num = -1000;
    for (int i = 0; i < n; i++) {
        // cout << "i=" << i << " count[i]=" << count[i] << endl;
        if (i == count[i]) max_num = max(max_num, count[i]);
    }

    cout << max_num << endl;

    return 0;
}
