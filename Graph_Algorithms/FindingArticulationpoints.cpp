#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<int> adj[N], tin(N, 0), low(N, 0);
bool Vis[N] = {0};
set<int> s;
int dfs_timer = 1;

// Time Complexity: O(N + M)
void dfs(int u, int parent) {
    int count = 0;
    Vis[u] = 1;
    tin[u] = low[u] = dfs_timer++;
    for (int v: adj[u]) {
        if (v == parent)    continue;
        if (Vis[v])
            low[u] = min(low[u], tin[v]);
        else {
            count += 1;
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= tin[u] && parent != 0) 
                s.insert(u);
        }
    }
    if (parent == 0 && count > 1)
        s.insert(u);
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int c = 1;
    for (int v = 1; v <= n; v++) {
        if (!Vis[v]) {
            dfs(v, 0);
            cout << "Component" << c++ << ":\n";
            for (int v: s) 
                cout << v << " ";
        }
    }
    return 0;
}

// Tarjan's Algorithm