#include<bits/stdc++.h>

using namespace std;
struct Edge {
    int u, v, wt;
    bool operator<(const Edge &b) const {
        return this -> wt < b.wt;
    }
};
vector<Edge> edges, res;

// Time Complexity: O(M logn + n^2)
int kruskal(int n) {
    int cost = 0;
    vector<int> treeId(n);
    for (int i = 0; i < n; i++)
        treeId[i] = i;
    sort(edges.begin(), edges.end());
    for (Edge e: edges) {
        if (treeId[e.u] != treeId[e.v]) {
            cost += e.wt;
            res.push_back(e);
            int oldId = treeId[e.u], newId = treeId[e.v];
            for (int i = 0; i < n; i++) {
                if (treeId[i] == oldId)
                    treeId[i] = newId;
            }
        }
    }
    return cost;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        u -= 1, v -= 1;
        edges.push_back({u, v, wt});
    }
    cout << "Cost: " << kruskal(n) << "\n";
    for (Edge e: res) {
        cout << e.u << " -> " << e.v << ": " << e.wt << "\n";
    }
    return 0;
}