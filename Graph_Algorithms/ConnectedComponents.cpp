#include<bits/stdc++.h>

using namespace std;
const int N = 1e3 + 1;
vector<int> adj[N], comp;
bool Vis[N] = {0};

void dfs(int u) {
    Vis[u] = 1;
    comp.push_back(u);
    for (int v: adj[u]) {
        if (!Vis[v]) {
            Vis[v] = 1;
            dfs(v);
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
    int c = 1;
    for (int i = 1; i <= n; i++) {
        comp.clear();
        if (!Vis[i]) {   
            dfs(i);
            cout << "Component" << c << ": ";
            c++;
            for (int v: comp) 
                cout << v << " ";
            cout << "\n";
        }
    }
    return 0;
}