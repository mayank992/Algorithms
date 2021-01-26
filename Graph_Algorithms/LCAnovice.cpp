#include<bits/stdc++.h>

using namespace std;
const int N = 14;
vector<int> adj[N], parent(N);
vector<int> depth(N, 0);

void dfs(int v, int p, int d) {
    parent[v] = p;
    depth[v] = d;
    for (int u: adj[v]) {
        if (u == p) continue;
        dfs(u, v, d + 1);
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v])
        swap(u, v);
    int d = depth[u] - depth[v];
    while (d > 0) {
        u = parent[u];
        d--;
    }
    while (u != v) {
        u = parent[u], v = parent[v];
    }
    return u;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0, 0);
    int q; cin >> q;
    while (q--) {
        int u, v; cin >> u >> v;
        cout << lca(u, v) << "\n";
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
