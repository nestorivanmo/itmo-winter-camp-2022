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

double f(double x) {
    return (x*x + sqrt(x));
}

double bin_search(double C) {
    double l = -1; while (f(l) > C) l *= 2;
    double r = 1; while(f(r) < C) r *= 2;
    for (int i = 0; i < 1000000; i++) {
        double m = (double) (l+r)/2;
        if (f(m) < C) l = m;
        else r = m;
        if (r == C) break;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    double C; cin >> C;
    cout.precision(6);
    printf("%f\n", bin_search(C));
    return 0;
}
