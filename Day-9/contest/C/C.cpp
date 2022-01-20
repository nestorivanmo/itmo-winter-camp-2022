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

vector<int> generate_candidates(int n, int k, vector<int> current_nums) {
    vector<int> candidates;
    if (current_nums.size() == 0) {
        for (int i = 1; i <= (n-k)+1; i++) {
            candidates.push_back(i);
        }
    } else {
        auto a = current_nums.back();
        for (int i = a+1; i <= n-1; i++) {
            candidates.push_back(i);
        }
        if (current_nums.size() == k-1) candidates.push_back(n);
    }
    return candidates;
}

void backtrack(int n, int k, vector<int> &nums) {
    if (nums.size() == k) {
        print_nums(nums);        
    }
    vector<int> candidates = generate_candidates(n, k, nums);
    for (auto c : candidates) {
        nums.push_back(c);
        backtrack(n, k, nums);
        nums.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, k; cin >> n >> k;
    vector<int> nums;
    backtrack(n, k, nums);
    return 0;
}
