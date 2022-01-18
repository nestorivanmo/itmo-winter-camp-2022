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

int n, k = 0;
vector<long long> tree, arr;

void print_tree() {
    for (int i = 0; i < tree.size(); i++) {
        cout << tree[i] << ' ';
    }
    cout << endl;
}

void tree_build() {
    k = 0;
    while ((1<<k) < n) k++;
    tree.resize((1<<k+1));
    int j = (1<<k);
    for (int i = 0; i < n; i++) {
        tree[j] = arr[i];
        j++;
    }
    for (int i = (1<<k)-1; i >= 1; i--) {
        tree[i] = tree[2*i] + tree[2*i+1];
    }
}

void tree_set(int pos, long long val) { // pos should be index zero
    int i = (1<<k) + pos;
    tree[i] = val;
    i /= 2;
    while (i != 0) {
        tree[i] = tree[2*i] + tree[2*i+1];
        i /= 2;
    }
}

long long tree_query(int node, int node_l, int node_r, int l, int r) {
    // printf("node=%d [%d:%d] [%d:%d]\n", node, node_l, node_r, l, r);
    if (node_l == l && node_r == r) {
        // printf("\t%d\n", tree[node]);
        return tree[node];
    }

    if (l > node_r || r < node_l) {
        // printf("\t0\n");
        return 0;
    }

    int node_m = (node_l + node_r) / 2;    
    return tree_query(2*node, node_l, node_m, l, min(node_m, r)) + 
    tree_query(2*node+1, node_m+1, node_r, max(node_m+1, l), r);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    tree_build();
    // print_tree();
    int node = 1, node_l = 0, node_r = (1<<k)-1;
    // cout << tree_query(node, node_l, node_r, 0, 3) << endl;

    string s;
    while (cin >> s) {
        if (s == "sum") {
            int l, r; cin >> l >> r;
            l--; r--;
            // cerr << "l=" << l << ' ' << "r=" << r << endl;
            cout << tree_query(node, node_l, node_r, l, r) << endl;
        } else {
            int p; long long val;
            cin >> p >> val;
            p--;
            tree_set(p, val);
        }
    }    
    return 0;
}