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

double remaining_time(int p, double s) {
    if (p > 20) {
        return (double) s*p + 20*s;
    } else {
        return (double) 2*s*p;
    }
}

double speed(int t, int p) {
    if (p > 20) {
        return (double) t/(100-p);
    } else {
        double tp = (double)(80*t)/(80 + 2*(20-p));
        return (double) tp/80;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();

    int t, p;
    double ans, s, rem_time;

    cin >> t >> p;
    s = speed(t, p);
    double tp = remaining_time(p, s);
    cout << tp << endl;

    return 0;
}