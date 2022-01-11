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

/*
for i = 0 to n-1
    cnt[a[i]]++
i = 0
for j = 0 to m-1
    while cnt[j] > 0
        a[i++] = j
        cnt[j]--
*/

vector<int> counting_sort(vector<int> a) {
    int m = -1;
    for (int i = 0; i < a.size(); i++) {
        m = max(m, a[i]);
    }
    // cout << "m=" << m << endl;
    vector<int> count(m+1), s;
    for (int i = 0; i < a.size(); i++) {
        count[a[i]]++;
    }

    // for (int i = 0; i <= m; i++) {
    //     cout << count[i] << ' ';
    // }
    // cout << endl;

    for (int i = 0; i <= m; i++) {
        if (count[i] != 0) {
            int times = count[i];
            while(times--) s.push_back(i);
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    vector<int> nums;
    int n;
    while (scanf("%d", &n) != EOF) nums.push_back(n);
    auto s_nums = counting_sort(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << s_nums[i] << ' ';
    }
    return 0;
}
