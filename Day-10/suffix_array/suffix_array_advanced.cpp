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
    vector<int> classes(s.begin(), s.end());
    vector<int> new_classes(n);
    vector<int> order(n);
    iota(order.begin(), order.end(), 0); // 0,1,2,...
    vector<int> new_order(n);
    vector<int> cnt(max(n+1, 128));
    for (int num : classes) {
        cnt[num+1]++;
    }
    for (int i = 1; i < cnt.size(); i++) {
        cnt[i] += cnt[i-1];
    }

    for (int l = 0; l < n; l = (l==0 ? 1 : l*2)) {
        
        for (int pos : order) {
            int st = (pos - l + n) % n;
            // value is classes[st]
            // cnt[value] is poosition in result
            new_order[cnt[classes[st]]] = st;
            ++cnt[classes[st]];
        }
        int cur = 0;
        cnt[0] = 0;
        pair<int,int> last_classes = {classes[new_order[0]], classes[(new_order[0]+l) % n]};
        for (int i = 0; i < n; i++) {
            pair<int,int> cur_classes = {classes[new_order[i]], classes[(new_order[i]+l) % n]};
            if (cur_classes != last_classes) {
                ++cur;
                cnt[cur] = i;
            }
            new_classes[new_order[i]] = cur;
        }
        swap(new_classes, classes);
        swap(new_order, order);
    }
    return order;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    string s; cin >> s;
    s += "$";
    vector<int> suffarr = build_suffarr(s);
    for (auto pos : suffarr) {
        cout << s.substr(pos) << endl;
    }
    return 0;
}
