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
    1+1+1+1
    1+1+2
    1+3
    2+2
    4
*/

bool is_solution(int n, vector<int> N) {
    int t = 0;
    for (auto it : N) {
        t += it;
    }
    return (t==n) ? true : false;
}

void print_nums(int n, vector<int> nums) {
    cout << n << "=";
    int a = nums.size();
    for (int i = 0; i < a-1; i++) {
        cout << nums[i] << '+';
    }
    cout << nums[a-1] << endl;
}

vector<int> generate_C(int n, vector<int> nums) {
    vector<int> C;
    int m = n/2;
    if (nums.size() == 0) {
        for (int i = 1; i <= m; i++) {
            C.push_back(i);
        }
        C.push_back(n);
    } else {
        auto a = nums.back();
        for (int i = a; i <= n; i++) {
            if (a+i == n) {
                C.push_back(i);
            } else if (a+i <= m) {
                C.push_back(i);
            }
        }
    }
    return C;
}

void backtrack(int n, vector<int>& nums) {
    if (is_solution(n, nums)) {
        print_nums(n, nums);
    }
    for (auto c : generate_C(n, nums)) {
        cerr << c << endl;
        nums.push_back(c);
        backtrack(n, nums);
        nums.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n; cin >> n;
    vector<int> nums = {};
    backtrack(n, nums);
    // auto c = generate_C(n, {1});
    // for (auto it : c) {
    //     cout << it << ' ';
    // }
    // cout << endl;
    return 0;
}
