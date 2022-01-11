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
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        int l_pos = lower_bound(nums.begin(), nums.end(), l) - nums.begin();
        int r_pos = lower_bound(nums.begin(), nums.end(), r+1) - nums.begin();
        cout << (r_pos - l_pos) << ' ';
    }
    cout << endl;
    return 0;
}