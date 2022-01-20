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

void print_nums(vector<int> nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

vector<int> generate_candidates(int n, vector<int> nums) {
    vector<int> candidates;
    for (int i = 1; i <= n; i++) {
        if (find(nums.begin(), nums.end(), i) == nums.end()) {
            candidates.push_back(i);
        }
    }
    return candidates;
}

void backtrack(int n, vector<int> &nums) {
    if (nums.size() == n) {
        print_nums(nums);
    }
    vector<int> candidates = generate_candidates(n, nums);
    for (auto c : candidates) {
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
    return 0;
}
