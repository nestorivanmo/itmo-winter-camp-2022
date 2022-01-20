#include <iostream>
#include <string>
#include <vector>
using namespace std;

void setIO(){
    string file = __FILE__;
    file = string(file.begin(), file.end()-3);
    string in_file = file+"in";
    string out_file = file+"out";
    freopen(in_file.c_str(), "r", stdin);
    freopen(out_file.c_str(), "w", stdout);
}

int main() {
    if (getenv("LOCAL")) {
        setIO();
    }
    int n; 
    cin >> n;
    vector<int> degrees(n);
    for(int i=0; i < n; i++) cin >> degrees[i];
    // iterate over all 2^n
    long long sum_of_subset;
    for (int subset = 0; subset < (1<<n); subset++) {
        sum_of_subset = 0;
        for (int bit=0; bit < n; bit++) {
            if (subset & (1<<bit)) {
                sum_of_subset += degrees[bit];
            } else {
                sum_of_subset -= degrees[bit];
            }
        }
        if (sum_of_subset % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}