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

vector<int> build_suffarr(string s) {
    int n = s.size();
    vector<int> classes(n);

    vector<pair<char,int>> tmp;
    for (int i = 0; i < n; i++) {
        tmp.push_back({s[i], i});
    }
    sort(tmp.begin(), tmp.end());
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (i != 0 && tmp[i-1].first != tmp[i].first) {
            cur++;
        }
        classes[tmp[i].second] = cur;
    }
    // cerr << s << endl;
    for (int l = 2; ; l*=2) {
        // cerr << "curr length " << l / 2 << endl;
        // for (int i = 0; i < n; i++) {
        //     cerr << classes[i] << ' ';
        // }
        // cerr << endl;
        vector<int> new_classes(n);
        vector<pair<pair<int,int>,int>> tmp;
        for (int i = 0; i < n; i++) {
            tmp.push_back({{classes[i], classes[(i + l / 2)%n]}, i});
        }
        sort(tmp.begin(), tmp.end());
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0 && tmp[i-1].first != tmp[i].first) {
                cur++;
            }
            new_classes[tmp[i].second] = cur;
        }
        classes = new_classes;
        if (l >= n) {
            break;
        }
    }
    vector<int> ret(n);
    for (int i = 0; i < n; i++) {
        ret[classes[i]] = i;
    }
    return ret;
}

vector<int> build_lcp(string s, vector<int> suffarr) {
    int n = s.size();
    vector<int> where(n);
    for (int i = 0; i < n; i++) {
        where[suffarr[i]] = i;
    }
    vector<int> lcp(n);
    int l = 0;
    for (int j = 0; j < n; j++) {
        if (where[j] == n-1) {
            l = 0;
            continue;
        }
        l = max(0, l-1);
        while (j + l < n && suffarr[where[j] + 1] + l < n && 
            s[j+l] == s[suffarr[where[j] + 1] + l]) {
            ++l;
        }
        lcp[where[j]] = l;
    }
    return lcp;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    string s; cin >> s;
    string t; cin >> t;
    s += "$";
    s += t;
    int n = s.size();
    vector<int> suffarr = build_suffarr(s);
    vector<int> lcp = build_lcp(s, suffarr);

    int max_lcp = -100000;
    string lcsubstring = "";
    string a, b;
    for (int i = 1; i < n-1; i++) {
        // cerr << lcp[i] << endl;
        // cerr << "\t" << s.substr(suffarr[i]) << " vs. " << s.substr(suffarr[i+1]) << endl;
        if (lcp[i] > max_lcp) {
            a = s.substr(suffarr[i]);
            b = s.substr(suffarr[i+1]);
            max_lcp = lcp[i];
            lcsubstring = "";
            for (int i = 0; i < max_lcp; i++) {
                lcsubstring += a[i];
            }
            // if ((a.find("$") == string::npos && b.find("$") != string::npos) || 
            //     (a.find("$") != string::npos && b.find("$") == string::npos)) {
            //     max_lcp = lcp[i];
            //     lcsubstring = "";
            //     for (int i = 0; i < max_lcp; i++) {
            //         lcsubstring += a[i];
            //     }
            // }
        }
    }
    cout << lcsubstring << endl;
    return 0;
}
