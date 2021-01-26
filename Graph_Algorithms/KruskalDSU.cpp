#include<bits/stdc++.h>

using namespace std;

struct Edge {
    int u, v, wt;
};

class DisjSet {
    private:
        int *parent, n;
    public:
        DisjSet(int n) {
            parent = new int[n]{0};
            memset(parent, -1, n * sizeof(int));
            this -> n = n;
        }
        int _find(int x) {
            // Path compression
            if(parent[x] >= 0) {
                parent[x] = _find(parent[x]);
            }
            else 
                return x; 
            return parent[x];
        }
        void _union(int x, int y) {
            int parent_x = _find(x);
            int parent_y = _find(y);
            if(parent_x == parent_y)
                return ;

            // Union by Rank
            if(abs(parent[parent_x]) < abs(parent[parent_y])) {
                parent[parent_x] = parent_y;
            }
            else if(abs(parent[parent_x]) > abs(parent[parent_y])) {
                parent[parent_y] = parent_x;
            }
            else {
                parent[parent_y] = parent_x;
                parent[parent_x] -= 1;
            }
        }
};
    
int main() {
    int n, m;
    cin >> n >> m;
    DisjSet ds(n + 1);
    vector<Edge> edges;
    for (int i = 0; i < n; i++) {
        int u, v, wt; cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    int totalWt = 0;
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {return a.wt < b.wt;});
    for (Edge e: edges) {
        int u = e.u, v = e.v, wt = e.wt;
        if (ds._find(u) != ds._find(v)) {
            totalWt += wt;
            ds._union(u, v);
        }
    }
    cout << totalWt;
    return 0;
}

// Time complexity: O(ElogE + V + E) => O(ElogV)
