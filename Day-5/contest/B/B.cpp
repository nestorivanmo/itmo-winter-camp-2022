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

vector<int> x_dir = {2, 2, -2, -2, 1, -1, 1, -1};
vector<int> y_dir = {1, -1, 1, -1, 2, 2, -2, -2};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();

    int N; cin >> N;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--; y1--;
    x2--; y2--;
    
    // BFS
    queue<pair<int,int>> q;
    vector<vector<pair<int,int>>> parent(N, vector<pair<int,int>>(N, {-1,-1}));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    visited[x1][y1] = true;
    q.push({x1, y1});
    while (!q.empty()) {        
        auto v = q.front();
        q.pop();
        for (int i = 0; i < x_dir.size(); i++) {
            int x = v.first + x_dir[i]; int y = v.second + y_dir[i];
            if (x < 0 || x >= N | y < 0 || y >= N) continue;
            if (!visited[x][y]) {
                visited[x][y] = true;
                parent[x][y] = v;
                if (x == x2 && y == y2) {
                    while(!q.empty()) q.pop();
                    break;
                }
                q.push({x,y});
            }
        }
    }

    vector<pair<int,int>> ans;
    pair<int,int> c = {x2,y2};
    while (parent[c.first][c.second] != parent[x1][y1]) {
        ans.push_back(c);
        c = parent[c.first][c.second];
    }
    ans.push_back({x1,y1});
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first+1 << ' ' << it.second+1 << endl;
    }
    
    return 0;
}
