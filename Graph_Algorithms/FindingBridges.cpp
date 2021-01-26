#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<int> adj[N], tin(N, 0), low(N, 0);
bool Vis[N] = {0};
set<pair<int, int>> s;
int dfs_timer = 1;

// Time Complexity: O(N + M)
void dfs(int u, int parent) {
    Vis[u] = 1;
    tin[u] = low[u] = dfs_timer++;
    for (int v: adj[u]) {
        if (v == parent)    continue;
        if (Vis[v]) 
            low[u] = min(low[u], tin[v]);
        else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > tin[u])
                s.insert(make_pair(u, v));
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // applying series of dfs for all the connected components in the graph
    int c = 1;
    for (int v = 1; v <= n; v++) {
        if (!Vis[v]) {
            dfs(v, 0);
            cout << "Component" << v << ":\n";
            for (pair<int, int> i: s)
                cout << i.first << " " << i.second << "\n";
            cout << "\n";
        }
    }
    return 0;
}

// Tarjan's Algorithms