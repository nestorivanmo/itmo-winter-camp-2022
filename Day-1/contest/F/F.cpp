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

long long f(long long n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n % 2 == 1) return f(n/2) + f((n/2)+1);
    else return f(n/2);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    long long n; cin >> n;
    cout << f(n) << endl;
    return 0;
}