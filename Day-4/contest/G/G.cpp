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

class DirectedGraph {
    int m_num_of_nodes;
    vector<vector<int>> m_adj;
    vector<int> m_color, m_topo_sort;
    int m_back_edges = 0;

    public:
        DirectedGraph(int num_of_nodes) {
            m_num_of_nodes = num_of_nodes;
            m_adj.resize(num_of_nodes);
            m_color.resize(num_of_nodes);
            m_topo_sort.resize(num_of_nodes);
        }

        void add(int u, int v) {
            m_adj[u].push_back(v);
        }

        bool IsAcyclic() {
            m_back_edges = 0; m_topo_sort.clear();
            for (int u = 0; u < m_num_of_nodes; u++) {
                if (m_color[u] == 0) {
                    DFS(u);
                }
            }
            return m_back_edges > 0 ? false : true;
        }

        vector<int> FindTopoSort() {
            if (!IsAcyclic()) return {};
            
            m_color.assign(m_num_of_nodes, 0);
            m_topo_sort.clear();

            for (int u = 0; u < m_num_of_nodes; u++) {
                if (m_color[u] == 0) {
                    DFS(u);
                }
            }
            reverse(m_topo_sort.begin(), m_topo_sort.end());
            return m_topo_sort;
        }
    
    private: 
        void DFS(int u) {
            m_color[u] = 1;
            for (auto v : m_adj[u]) {
                if (m_color[v] == 0) {
                    DFS(v);
                } else if (m_color[v] == 1) {
                    m_back_edges++;
                }
            }
            m_color[u] = 2;
            m_topo_sort.push_back(u);
        }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    if (getenv("LOCAL")) setIO();
    int n, m; cin >> n >> m;
    DirectedGraph g {n};
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        g.add(u,v);
    }
    if (g.IsAcyclic()) {
        auto t = g.FindTopoSort();
        for (auto it : t) {
            cout << it+1 << ' ';
        }
    } else {
        cout << "-1" << endl;
    }
    return 0;
}
