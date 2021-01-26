#include<bits/stdc++.h>

using namespace std;
#define pb push_back
const int N = 1e5 + 1;
vector<int> adj[N];
vector<bool> color;

int dfs(int v, int parent) {
    for (int u: adj[v]) {
        if (u == parent) continue;
        
    }
}

int main() {
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int u; cin >> u;
        adj[u].pb(i); adj[i].pb(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }
    int res = dfs(0, -1);
    return 0;
}