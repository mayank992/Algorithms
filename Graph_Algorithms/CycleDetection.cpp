#include<bits/stdc++.h>

using namespace std;
vector<int> adj[100];
bool Vis[100] = {0};

bool isCycleExistUD(int src, int parent) {
    Vis[src] = 1;
    for (int u: adj[src]) {
        if (!Vis[u]) {
            if (isCycleExistUD(u, src)) return 1;
        }
        else if (u != parent)
            return 1;
    }
    return 0;
}

bool path[100] = {0};
bool isCycleExistD(int src) {
    Vis[src] = 1;
    path[src] = 1;
    for (int u: adj[src]) {
        if (path[u])    return 1;   // cycle exist or not
        if (!Vis[u]) 
            if (isCycleExistD(u))  return 1;
    }
    path[src] = 0;
    return 0;
}

int main() {
    int n, edges;
    cin >> n >> edges;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    if (isCycleExistD(0))
        cout << "Cycle exist.\n";
    else 
        cout << "Cycle doesn't exist.\n";
    return 0;
}