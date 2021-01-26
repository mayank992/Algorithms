#include<bits/stdc++.h>

using namespace std;
/*
    * You are given a directed graph G with vertices V and edges E.
    
    * Strongly connected component is subset of vertices C such that any two vertices of this 
    subset are reachable from each other, i.e. for any u,v∈C:
    u -> v,v -> u
        where -> means reachability, i.e. existence of the path from first vertex to the second.
*/
const int N = 1e3 + 1;
vector<int> adj[N], adjt[N], order, scc;
bool Vis[N];

void dfs1(int u) {
    Vis[u] = 1;
    for (int v: adj[u]) {
        if (!Vis[v]) {
            dfs1(v);
        }
    }
    order.push_back(u);
}

void dfs2(int u) {
    Vis[u] = 1;
    scc.push_back(u);
    for (int v: adjt[u]) {
        if (!Vis[v]) {
            dfs2(v);
        }
    }    
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;   cin >> u >> v;
        adj[u].push_back(v);
        adjt[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!Vis[i])
            dfs1(i);
    }
    int c = 1;  memset(Vis, 0, sizeof(Vis));
    while (!order.empty()) {
        int v = order.back();
        order.pop_back();
        if (!Vis[v]) {
            dfs2(v);
            cout << "Component" << c++ << ": ";
            for (int i: scc)
                cout << i << " ";
            cout << "\n";
            scc.clear();
        }
    }
    return 0;
}