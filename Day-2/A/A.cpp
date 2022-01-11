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

vector<int> merge(vector<int> a, vector<int> b) {
    int n = a.size(); 
    int m = b.size();
    vector<int> c(n+m);
    int i = 0, j = 0;
    while ((i + j) < (n + m)) {
        if ((j == m) or (i < n and a[i] < b[j])) {
            c[i+j] = a[i];
            i++;
        } else {
            c[i+j] = b[j];
            j++;
        }
    }
    return c;
}

vector<int> merge_sort(vector<int> a) {
    int n = a.size();
    if (n == 1) return a;
    vector<int> l, r;
    for (int i = 0; i < (n/2); i++) {
        l.push_back(a[i]);
    }
    for (int i = (n/2); i < n; i++) {
        r.push_back(a[i]);
    }
    l = merge_sort(l);
    r = merge_sort(r);
    return merge(l, r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    vector<int> s_nums = merge_sort(nums);
    for (int i = 0; i < s_nums.size(); i++) {
        cout << s_nums[i] << ' ';
    }
    cout << endl;
    return 0;
}
