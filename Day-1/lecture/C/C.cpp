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

int mul(int a, int b, int m) {
    return (int)((long long) a * b % m);
}

int powerRecursive(int a, int b, int m) {
    if (b == 0) {
        return 1;
    }
    int result = mul(powerRecursive(a, b/2, m), powerRecursive(a, b/2, m), m);
    if (b % 2 == 1) {
        result = mul(result, a, m);
    }
    return result;
}

int main() {
    if (getenv("LOCAL")) setIO();
    int a, b, m; 
    cin >> a >> b >> m;
    cout << powerRecursive(a, b, m) << endl;
    return 0;
}